#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;
using namespace sf;

// `constexpr` defines an immutable compile-time value
constexpr int windowWidth{800}, windowHeight{600};

// Let's create some constants for the Ball class
constexpr float ballRadius{10.f}, ballVelocity{8.f};

// Let's create some constants for the paddle
constexpr float paddleWidth{60.f}, paddleHeight{20.f}, paddleVelocity{6.f};

// Let's define some constants for the bricks
constexpr float blockWidth{60.f}, blockHeight{20.f};
constexpr int countBlocksX{11}, countBlocksY{4};

// Let's create a class for our Ball
struct Ball
{
    // CircleShape is an SFML class that
    // defeines a renderable circle
    CircleShape shape;

    // 2D vector that stores the Ball's velocity
    Vector2f velocity{-ballVelocity, -ballVelocity};

    // Let's create the Ball constructor
    // argument mX -> starting x coordinate
    // argument mY -> starting y coordinate
    Ball(float mX, float mY) {
        // Apply position, radius, color and origin
        // to the CircleShape `shape`
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }

    // Let's "update" the ball: move its shape
    // by the current velocity
    void update() {
        shape.move(velocity);

        // We need to keep the ball "iside the screen"

        // If it's leaving toward the left, we need to set
        // horizontal velocity to a position value (toward the right)
        if (left() < 0)
            velocity.x = ballVelocity;

        // Otherwise, if it's leaving toward the right, we need to
        // set horizontal velocity to a negative value (toward the left)
        else if (right() > windowWidth)
            velocity.x = -ballVelocity;

        // The same idea can be applied for top/bottom collisions
        if (top() < 0)
            velocity.y = ballVelocity;
        else if (bottom() > windowHeight)
            velocity.y = -ballVelocity;
    }

    // We can also create "property" methods to easily
    // get commonly used values
    float x()       { return shape.getPosition().x; }
    float y()       { return shape.getPosition().y; }
    float left()    { return x() - shape.getRadius(); }
    float right()   { return x() + shape.getRadius(); }
    float top()     { return y() - shape.getRadius(); }
    float bottom()  { return y() + shape.getRadius(); }
};

// Let's create a `Paddle` class, similar to `Ball`
struct Paddle
{
    // RectangleShape is an SFML class that defines
    // a renderable rectangular shape
    RectangleShape shape;
    Vector2f velocity;

    // As with the ball, we construct the paddle with
    // arguments for initial position and pass the values
    // to the SFML `shape`
    Paddle(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({paddleWidth, paddleHeight});
        shape.setFillColor(Color::Green);
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
    }

    void update() {
        shape.move(velocity);

        // To move the paddle, we check if the user is pressing
        // the left or right arrow key: if so, we change the velocity

        // To keep the paddle "inside the window", we change the velocity
        // only if its position is inside the window
        if (Keyboard::isKeyPressed(Keyboard::Key::Left)
                && left() > 0)
            velocity.x = -paddleVelocity;
        else if (Keyboard::isKeyPressed(Keyboard::Key::Right)
                && right() < windowWidth)
            velocity.x = paddleVelocity;

        // If the user isn't pressing anything, stop moving
        else
            velocity.x = 0;
    }

    float x()       { return shape.getPosition().x; }
    float y()       { return shape.getPosition().y; }
    float left()    { return x() - shape.getSize().x / 2.f; }
    float right()   { return x() + shape.getSize().x / 2.f; }
    float top()     { return y() - shape.getSize().y / 2.f; }
    float bottom()  { return y() + shape.getSize().y / 2.f; }
};

// Let's have a class `Brick` for the bricks
struct Brick
{
    RectangleShape shape;

    // This boolean value will be used to check
    // whether a brick has been hit or not
    bool destroyed{false};

    // The constructor is almost identical to the `Paddle` one
    Brick(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({blockWidth, blockHeight});
        shape.setFillColor(Color::Yellow);
        shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
    }

    float x()       { return shape.getPosition().x; }
    float y()       { return shape.getPosition().y; }
    float left()    { return x() - shape.getSize().x / 2.f; }
    float right()   { return x() + shape.getSize().x / 2.f; }
    float top()     { return y() - shape.getSize().y / 2.f; }
    float bottom()  { return y() + shape.getSize().y / 2.f; }
};
        
// Dealing with collisions: let's define a generic function
// to check if two shapes are intersecting (colliding)
template<class T1, class T2>
bool isIntersecting(T1& mA, T2& mB)
{
    return mA.right() >= mB.left() && mA.left() <= mB.right()
        && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

// Let's define a function that deals with paddle/ball collision
void testCollision(Paddle& mPaddle, Ball& mBall)
{
    // If there's no intersection, get out of the function
    if (!isIntersecting(mPaddle, mBall))
        return;

    // Otherwise let's "push" the ball upwards
    mBall.velocity.y = -ballVelocity;

    // And let's direct it dependently on the position where the
    // paddle was hit
    if (mBall.x() < mPaddle.x())
        mBall.velocity.x = -ballVelocity;
    else
        mBall.velocity.x = ballVelocity;
}

// Here's the most complex part of our game: ball-brick collison
void testCollision(Brick& mBrick, Ball& mBall)
{
    // If there's no intersection, get out of the function
    if (!isIntersecting(mBrick, mBall))
        return;

    // Otherwise, the brick has been hit!
    mBrick.destroyed = true;

    // Let's calculate how much the ball intersects the brick
    // in every direction
    float overlapLeft{mBall.right() - mBrick.left()};
    float overlapRight{mBrick.right() - mBall.left()};
    float overlapTop{mBall.bottom() - mBrick.top()};
    float overlapBottom{mBrick.bottom() - mBall.top()};

    // If the magnitude of the left overlap is smaller than the
    // right one we can safely assume the ball hit the brick
    // from the left
    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));

    // We can apply the same idea for top/bottom collisions
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    // Let's store the minimum overlaps for the X and Y axes
    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

    // If the magnitude of the X overlap is less than the magnitude
    // of the Y overlap, we can safely assume the ball hit the brick
    // horizontally - otherwise, the ball hit the brick vertically

    // Then, upon our assumptions, we change either the X or Y velocity
    // of the ball, creating a "realistic" response forthe collision
    if (abs(minOverlapX) < abs(minOverlapY))
        mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    else
        mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

int main(void)
{
    // Let's create an instance of `Ball`
    // postioned at the center of the window
    Ball ball{windowWidth / 2, windowHeight / 2};

    // Let's create a `Paddle` instance
    Paddle paddle{windowWidth / 2, windowHeight - 50};

    // We wil use an `std::vector` to contain any number
    // of `Brick` instances
    vector<Brick> bricks;

    // We fill up our vector via a 2D for loop, creating
    // bricks in a grid-like pattern
    for (int iX{0}; iX < countBlocksX; ++iX)
        for (int iY{0}; iY < countBlocksY; ++iY)
            bricks.emplace_back((iX + 1) * (blockWidth + 3) + 22,
                                (iY + 2) * (blockHeight + 3));

    // Creation of the game window
    RenderWindow window{{windowWidth, windowHeight}, "Arkanoid - 8"};
    window.setFramerateLimit(60);

    // Game loop
    while(true) {
        // "Clear" the window from previously drawn graphics
        window.clear(Color::Black);

        // If "Escape" is pressed, break out of the loop
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            break;

        // Every loop iteration, we need to udate the ball
        ball.update();

        // Let's update our `paddle` ...
        paddle.update();

        // Let's test the collision every game loop iteration
        testCollision(paddle, ball);

        // We use another C++11 foreach loop to test collisions
        // between the ball and EVERY brick
        for (auto& brick : bricks)
            testCollision(brick, ball);

        // And we use a STL algorithm to remove all `destroyed` blocks
        // from the block vector - using a cool c++11 lambda!
        bricks.erase(remove_if(begin(bricks), end(bricks),
                    [](const Brick& mBrick){ return mBrick.destroyed; }),
                end(bricks));

        // Let's render the Ball instance on the wndow
        window.draw(ball.shape);

        // ... and draw its shape on the window
        window.draw(paddle.shape);

        // We must draw every brick on the window!
        // Let's use a modern C++11 foreach loop, that allows
        // us to intuitively say: "draw every `brick` in `bricks`"
        for (auto& brick : bricks)
            window.draw(brick.shape);

        // Show the window contents
        window.display();
    }

    return 0;
}

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// `constexpr` defines an immutable compile-time value
constexpr int windowWidth{800}, windowHeight{600};

// Let's create some constants for the Ball class
constexpr float ballRadius{10.f}, ballVelocity{8.f};

// Let's create some constants for the paddle
constexpr float paddleWidth{60.f}, paddleHeight{20.f}, paddleVelocity{6.f};

// Let's create a class for our Ball
// `struct` == `class` in C++
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
        else velocity.x = 0;
    }

    float x()       { return shape.getPosition().x; }
    float y()       { return shape.getPosition().y; }
    float left()    { return x() - shape.getSize().x / 2.f; }
    float right()   { return x() + shape.getSize().x / 2.f; }
    float top()     { return y() - shape.getSize().y / 2.f; }
    float bottom()  { return y() + shape.getSize().y / 2.f; }
};

int main()
{
    // Let's create an instance of `Ball`
    // postioned at the center of the window
    Ball ball{windowWidth / 2, windowHeight / 2};

    // Let's create a `Paddle` instance
    Paddle paddle{windowWidth / 2, windowHeight - 50};

    // Creation of the game window
    RenderWindow window{{windowWidth, windowHeight}, "Arkanoid - 5"};
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

        // Let's render the Ball instance on the wndow
        window.draw(ball.shape);

        // ... and draw its shape on the window
        window.draw(paddle.shape);

        // Show the window contents
        window.display();
    }

    return 0;
}

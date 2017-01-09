#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// `constexpr` defines an immutable compile-time value
constexpr int windowWidth{800}, windowHeight{600};

// Let's create some constants for the Ball class
constexpr float ballRadius{10.f}, ballVelocity{8.f};

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

int main()
{
    // Let's create an instance of `Ball`
    // postioned at the center of the window
    Ball ball{windowWidth / 2, windowHeight / 2};

    // Creation of the game window
    RenderWindow window{{windowWidth, windowHeight}, "Arkanoid - 4"};
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

        // Let's render the Ball instance on the wndow
        window.draw(ball.shape);

        // Show the window contents
        window.display();
    }

    return 0;
}

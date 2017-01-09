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
    }
};

int main()
{
    // Let's create an instance of `Ball`
    // postioned at the center of the window
    Ball ball{windowWidth / 2, windowHeight / 2};

    // Creation of the game window
    RenderWindow window{{windowWidth, windowHeight}, "Arkanoid - 3"};
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

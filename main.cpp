#include <SFML/Graphics.hpp>
using namespace sf;

float speedX = -4.f;
float speedY = -4.f;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    RectangleShape shape({60.f, 30.f});
    shape.setPosition({400,300});
    shape.setFillColor({190, 0, 150});
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(Mouse::isButtonPressed(Mouse::Left)){
            shape.rotate(15);
        }
        if(Mouse::isButtonPressed(Mouse::Right)){
            shape.rotate(-15);
        }

        //window.clear();
        if (shape.getPosition().x + shape.getSize().x > 800 ||
            shape.getPosition().x < 0)
        {

            shape.setFillColor({rand()%255,rand()%255, rand()%255});
            speedX *= -1;
        }

        if (shape.getPosition().y + shape.getSize().y > 600 ||
            shape.getPosition().y < 0)
        {
            shape.setFillColor({rand()%255,rand()%255, rand()%255});
            speedY *= -1;
        }

        shape.move(speedX, speedY);
        window.draw(shape);
        window.display();
    }

    return 0;
}

struct Vector2f
{
    float x;
    float y;
};
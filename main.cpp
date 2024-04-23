#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;


int main()
{
    // setup
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(60.f, 30.f), {400,300});
    vector<Rectangle> rectangulos;

    // loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

// escucha 1 vez cuando se presiona el click izquierdo del mouse
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    float x = float(rand() % 100);
                    float y = float(rand() % 100);
                    Rectangle r = Rectangle(Vector2f(x, y)                  , Mouse::getPosition(window));
                    rectangulos.push_back(r);

                    Mouse::getPosition(window);
                }
            }
        }

// Entra al if si el click izquierdo está presionado.
        if(Mouse::isButtonPressed(Mouse::Left))
        {}


        window.clear();
        rect.update();
        rect.drawTo(window);
        for(auto &r : rectangulos){
            r.update();
            r.drawTo(window);
        }

        window.display();
    }

    return 0;
}

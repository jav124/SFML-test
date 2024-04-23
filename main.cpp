#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

float d = 25.f;
vector<Ball> balls;
Ball ball(d);

void loop(RenderWindow &window);

int main()
{
    RenderWindow window(VideoMode(600, 400), "SFML works!");
    window.setFramerateLimit(60);
    loop(window);

    return 0;
}

void loop(RenderWindow &window)
{
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if left mouse button is pressed
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    Ball b(d, Mouse::getPosition(window).x, Mouse::getPosition(window).y);
                    balls.push_back(b);

                    
                }
            }
        }

        window.clear();
        ball.update();
        ball.draw(window);
        for (auto &b : balls)
        {
            b.update();
            b.draw(window);
        }

        window.display();
    }
}
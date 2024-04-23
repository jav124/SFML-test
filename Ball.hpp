#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    CircleShape shape;

    Vector2f speed;
    Vector2f acc;

public:
    Ball(float d)
    {
        this->shape.setRadius(d);
        this->shape.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        this->speed = Vector2f(4.f, 0.f);
        this->acc = Vector2f(0.f, 1.f);
    }

    Ball(float d, int x, int y) : Ball(d)
    {
        this->setPos(x, y);
    }

    void update()
    {
        if (this->shape.getPosition().y + 2 * this->shape.getRadius() <= 400)
        {

            this->speed = this->speed + this->acc;
            shape.move(this->speed);
        }
        if (this->shape.getPosition().x >= 600 - 2 * this->shape.getRadius() || this->shape.getPosition().x < 0)
        {
            this->speed.x *= -1;
        }
        if (this->shape.getPosition().y + 2 * this->shape.getRadius() >= 400)
        {
            this->speed.y *= -1;
        }
        if (this->shape.getPosition().y + 2 * this->shape.getRadius() > 400)
        {

            this->shape.setPosition(this->shape.getPosition().x, 400 - 2 * this->shape.getRadius());
        }
    }

    void setPos(float x, float y)
    {
        this->shape.setPosition(x - this->shape.getRadius(), y - this->shape.getRadius());
    }

    void draw(RenderWindow &window)
    {
        window.draw(this->shape);
    }
};

#endif
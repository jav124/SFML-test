#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2f size, Vector2i position)
{
    this->shape = RectangleShape(size);
    this->shape.setPosition(Vector2f(position));
    this->shape.setFillColor(Color(190, 0, 150));
    this->speed = Vector2f(4.f, 4.f);
}

void Rectangle::update()
{
    if (this->shape.getPosition().x + this->shape.getSize().x > 800 ||
        this->shape.getPosition().x < 0)
    {
        this->shape.setFillColor({rand() % 255, rand() % 255, rand() % 255});
        this->speed.x *= -1;
    }
    if (this->shape.getPosition().y + this->shape.getSize().y > 600 ||
        this->shape.getPosition().y < 0)
    {
        this->shape.setFillColor({rand() % 255, rand() % 255, rand() % 255});
        this->speed.y *= -1;
    }
    this->shape.move(this->speed);
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}

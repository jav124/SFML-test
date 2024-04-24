#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int width = 400;
int numCells = 20;
int size = width / numCells;
vector<vector<int>> grid(numCells, vector<int>(numCells, 0));
vector<vector<int>> nextGrid(numCells, vector<int>(numCells, 0));

void setToZero(vector<vector<int>> &grid);
void drawGrid(RenderWindow &window);
void updateGrid();
void logGrid();

int main()
{
    RenderWindow window(VideoMode(width, width), "SFML works!");
    window.setFramerateLimit(3);
    setToZero(grid);
    setToZero(nextGrid);
    bool play = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x / (width / numCells);
                    int y = event.mouseButton.y / (width / numCells);
                    grid[y][x] = (grid[y][x] + 1)%2;
                }
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Space)
                {
                    play = !play;
                }
            }
        }

        window.clear();
        if (play)
        {
            updateGrid();
        }
        drawGrid(window);
        window.display();
    }

    return 0;
}

void setToZero(vector<vector<int>> &arr)
{
    for (int i = 0; i < numCells; i++)
    {
        for (int j = 0; j < numCells; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void drawGrid(RenderWindow &window)
{
    int size = width / numCells;
    RectangleShape rectangle(Vector2f(size, size));
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(1);
    for (int i = 0; i < numCells; i++)
    {
        for (int j = 0; j < numCells; j++)
        {
            if (grid[j][i] == 1)
            {
                rectangle.setFillColor(Color::Green);
            }
            else
            {
                rectangle.setFillColor(Color::White);
            }
            rectangle.setPosition(i * size, j * size);
            window.draw(rectangle);
        }
    }
}

void logGrid()
{
    for (int i = 0; i < numCells; i++)
    {
        for (int j = 0; j < numCells; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void updateGrid()
{
    setToZero(nextGrid);
    for (int i = 0; i < numCells; i++)
    {
        for (int j = 0; j < numCells; j++)
        {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                    {
                        continue;
                    }
                    int xIndex = i + x;
                    int yIndex = j + y;
                    if (xIndex >= 0 && xIndex < numCells && yIndex >= 0 && yIndex < numCells)
                    {
                        if (grid[yIndex][xIndex] == 1)
                            neighbors++;
                    }
                }
            }
            if (grid[j][i] == 1)
            {
                if (neighbors < 2 || neighbors > 3)
                {
                    nextGrid[j][i] = 0;
                }
                else
                {
                    nextGrid[j][i] = 1;
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    nextGrid[j][i] = 1;
                }
            }
        }
    }
    grid = nextGrid;
}
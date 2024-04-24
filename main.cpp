#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int width = 400;
int numCells = 50;
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
    window.setFramerateLimit(45);
    setToZero(grid);
    setToZero(nextGrid);
    bool play = true;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseMoved)
            {
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    int x = event.mouseMove.x / (width / numCells);
                    int y = event.mouseMove.y / (width / numCells);
                    grid[y][x] = 1;
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
            cout << grid[j][i] << " ";
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
            if (grid[j][i] == 0)
                continue;
            if (grid[j][i] == 1)
            {
                if (j < numCells - 1 &&
                    grid[j + 1][i] == 0)
                {
                    nextGrid[j + 1][i] = 1;
                    nextGrid[j][i] = 0;
                }
                else
                {
                    if (j < numCells - 2 && (grid[j + 2][i - 1] == 0 || grid[j + 2][i + 1] == 0))
                    {
                        if (rand() % 2 == 0)
                        {
                            if (grid[j + 2][i - 1] == 0)
                            {
                                nextGrid[j + 2][i - 1] = 1;
                            }
                            else if (grid[j + 2][i + 1] == 0)
                            {
                                nextGrid[j + 2][i + 1] = 1;
                            }
                        }
                        else
                        {
                            if (grid[j + 2][i + 1] == 0)
                            {
                                nextGrid[j + 2][i - 1] = 1;
                            }
                            else if (grid[j + 2][i - 1] == 0)
                            {
                                nextGrid[j + 2][i + 1] = 1;
                            }
                        }
                    }
                    else
                    {
                        nextGrid[j][i] = 1;
                    }
                }
            }
        }
    }
    grid = nextGrid;
}
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;
int r = -1, c = -1;
const int Rows = 8;
const int Columns = 10;
RenderWindow window(VideoMode(1920, 1080), "Laser Chess");
Color backgroundcolor(255, 239, 226, 255);
Texture logo;
Sprite logoo;
Texture Red;
Sprite Redplayer;
Texture Blue;
Sprite Blueplayer;
RectangleShape grid[Rows][Columns];
RectangleShape KillsBoard;
Texture board;
Sprite grd;
Font font;
Text text1;
Text text2;

struct cell {
    bool isempty = true;
    Vector2f Position;
};
cell table[Rows][Columns];

void Start();
void Update();
void Draw();
void index(Vector2i mouseposition);

int main()
{

    Start();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                index(Mouse::getPosition(window));
            }

        }

        Update();
        Draw();


    }

}
void Start() {
    logo.loadFromFile("logo.png");
    logoo.setTexture(logo);
    Red.loadFromFile("Redplayer.png");
    Redplayer.setTexture(Red);
    Blue.loadFromFile("blueplayer.png");
    Blueplayer.setTexture(Blue);
    Blueplayer.setScale(0.12, 0.12);
    Redplayer.setScale(0.12, 0.12);
    logoo.setScale(0.6, 0.6);
    logoo.setPosition(150, 25);
    Redplayer.setPosition(242, 160);
    Blueplayer.setPosition(242, 765);
    board.loadFromFile("grid.png");
    grd.setTexture(board);
    grd.setPosition(245, 212);
    font.loadFromFile("arial.ttf");
    text1.setFont(font);
    text1.setString("Red Player");
    text1.setFillColor(Color::Red);
    text1.setStyle(Text::Bold);
    text1.setPosition(302, 165);
    text2.setFont(font);
    text2.setString("Blue Player");
    text2.setFillColor(Color(13, 110, 253, 255));
    text2.setStyle(Text::Bold);
    text2.setPosition(302, 768);
    KillsBoard.setSize(Vector2f(68, 820));
    KillsBoard.setOutlineColor(Color::White);
    KillsBoard.setOutlineThickness(2);
    KillsBoard.setPosition(1200, 110);
    KillsBoard.setFillColor(Color(222, 201, 180, 1200));
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            grid[i][j].setSize(Vector2f(65.4, 65.4));
            grid[i][j].setFillColor(Color(0, 0, 0, 0));
            grid[i][j].setOutlineColor(Color::White);
            grid[i][j].setPosition((j * 65.4) + 289, (i * 65.4) + 258);
            grid[i][j].setOutlineThickness(1);
            grid[i][j].setOrigin(grid[i][j].getLocalBounds().width / 2, grid[i][j].getLocalBounds().height / 2);
            table[i][j].isempty = true;
        }
    }


}

void Update() {

}
pair<int, int> getCellIndex(Vector2i mouseposition) {
    if (mouseposition.y > 225 && mouseposition.y < 745 && mouseposition.x > 258 && mouseposition.x < 914) {
        r = (mouseposition.y - 226) / 65.4;
        c = (mouseposition.x - 257) / 65.4;
        return { r, c };
    }

}
void index(Vector2i mouseposition) {
    pair<int, int> index = getCellIndex(mouseposition);
    static int prev_r = -1, prev_c = -1;

    if (r != prev_r || c != prev_c) {
       cout << index.first << " " << index.second << endl;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Columns; j++) {
                grid[i][j].setFillColor(Color(0, 0, 0, 0));
            }
        }

        if (r >= 0 && r < Rows && c >= 0 && c < Columns) {
            if (r - 1 >= 0) grid[r - 1][c].setFillColor(Color::Green);
            if (r + 1 < Rows) grid[r + 1][c].setFillColor(Color::Green);
            if (c - 1 >= 0) grid[r][c - 1].setFillColor(Color::Green);
            if (c + 1 < Columns) grid[r][c + 1].setFillColor(Color::Green);
            if (r - 1 >= 0 && c - 1 >= 0) grid[r - 1][c - 1].setFillColor(Color::Green);
            if (r - 1 >= 0 && c + 1 < Columns) grid[r - 1][c + 1].setFillColor(Color::Green);
            if (r + 1 < Rows && c - 1 >= 0) grid[r + 1][c - 1].setFillColor(Color::Green);
            if (r + 1 < Rows && c + 1 < Columns) grid[r + 1][c + 1].setFillColor(Color::Green);
        }

        prev_r = r;
        prev_c = c;
    }
}


void Draw() {

    window.clear(backgroundcolor);
    window.draw(logoo);
    window.draw(Blueplayer);
    window.draw(Redplayer);
    window.draw(grd);
    window.draw(text1);
    window.draw(text2);
    window.draw(KillsBoard);
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            window.draw(grid[i][j]);
        }
    }


    window.display();

}
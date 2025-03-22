#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;
int r, c,Tr,Tc;
const int Rows = 8;
const int Columns = 10;
RenderWindow window(VideoMode(1920, 1080), "Laser Chess");
Color backgroundcolor(255,239,226,1);
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
    int  cells[Rows][Columns];
};
cell table;
void Start();
void Update();
void Draw();
int index();
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

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mouseposition = Mouse::getPosition(window);
                    cout << mouseposition.x << " " << mouseposition.y << endl;

                }
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
    Blueplayer.setScale(0.12,0.12);
    Redplayer.setScale(0.12, 0.12);
    logoo.setScale(0.6,0.6);
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
    text1.setPosition(302,165);
    text2.setFont(font);
    text2.setString("Blue Player");
    text2.setFillColor(Color(13, 110, 253, 255));
    text2.setStyle(Text::Bold);
    text2.setPosition(302, 768);
    KillsBoard.setSize(Vector2f(68,820));
    KillsBoard.setOutlineColor(Color::White);
    KillsBoard.setOutlineThickness(2);
    KillsBoard.setPosition(1200,110);
    KillsBoard.setFillColor(Color(222,201,180,1200));
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            grid[i][j].setSize(Vector2f(65.4, 65.4));
            grid[i][j].setFillColor(Color(0, 0, 0, 0));
            grid[i][j].setOutlineColor(Color::White);
            grid[i][j].setPosition((j * 65.4) + 255 , (i * 65.4) + 224);
            grid[i][j].setOutlineThickness(1);
            
           // table.cells[Tr][Tc];
        }
    }


}

void Update() {
    cell grid;
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i mousePos = Mouse::getPosition(window);
        r = ((mousePos.x - 258) / 65);
        c = ((mousePos.y - 225) / 65);

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
int index()
{

    return c, r;
}

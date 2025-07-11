#include <string>
#ifndef WALL_H
#define WALL_H

using namespace std;


class Wall{
private:
    string localPath;
    Image img;
    Texture2D sprite;
    Vector2 pos;
    Rectangle hitBox;

public:
    Wall(string localPathIn, Vector2 startingPos);

    void drawWall();
    void drawWall(int posX, int posY);
    //void moveWall();

};

#endif
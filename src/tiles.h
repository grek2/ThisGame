#include <string>
#ifndef TILES_H
#define TILES_H

using namespace std;


class Tile{
private:
    string localPath;
    Image img;
    Texture2D sprite;
    Vector2 pos;
    Rectangle hitBox;

public:
    Tile(string localPathIn, Vector2 startingPos);

    void drawTile(int posX, int posY);

};

#endif
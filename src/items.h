#include <string>
#ifndef ITEMS_H
#define ITEMS_H

using namespace std;


class Item{
private:
    string localPath;
    Image img;
    Texture2D sprite;
    Vector2 pos;
    Rectangle hitBox;

public:
    Item(string localPathIn, Vector2 startingPos);

    void drawItem(int posX, int posY);
    void drawItem();
    void rotateItem();

};

#endif
#include "raylib.h"
#include "tiles.h"
#include <string>

using namespace std;



Tile::Tile(string localPathIn, Vector2 startingPos){
    localPath = localPathIn;
    img = LoadImage(localPathIn.c_str());
    ImageResizeNN(&img, 100, 100);

    sprite=LoadTextureFromImage(img);
    pos = startingPos;
    hitBox={pos.x, pos.y, (float) sprite.width,(float) sprite.height};


}

void Tile::drawTile(int posX, int posY){
    DrawTexture(sprite,posX,posY,BLUE);
}


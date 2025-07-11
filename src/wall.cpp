#include "raylib.h"
#include "wall.h"
#include <string>

using namespace std;

/*
Wall::Wall(){
    localPath = localPathIn;
    img = LoadImage(localPathIn.c_str());
    ImageResizeNN(&img, 100, 100);

    sprite=LoadTextureFromImage(img);
    pos = startingPos;
    hitBox={pos.x, pos.y, (float) sprite.width,(float) sprite.height};


}
    */

Color wallColor {250, 250, 255, 230};

Wall::Wall(string localPathIn, Vector2 startingPos){
    localPath = localPathIn;
    img = LoadImage(localPathIn.c_str());
    ImageResizeNN(&img, 100, 100);

    sprite=LoadTextureFromImage(img);
    pos = startingPos;
    hitBox={pos.x, pos.y, (float) sprite.width,(float) sprite.height};


}

void Wall::drawWall(){
    DrawTexture(sprite,pos.x,pos.y,wallColor);
}

void Wall::drawWall(int posX, int posY){
    DrawTexture(sprite,posX,posY,wallColor);
}

//void Wall::moveWall(){}
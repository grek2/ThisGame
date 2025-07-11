#include "raylib.h"
#include "items.h"
#include <string>

using namespace std;

Color bluee = {245, 230, 255, 100};


Item::Item(string localPathIn, Vector2 startingPos){
    localPath = localPathIn;
    img = LoadImage(localPathIn.c_str());
    ImageResizeNN(&img, 100, 100);
    
    sprite=LoadTextureFromImage(img);
    pos = startingPos;
    hitBox={pos.x, pos.y, (float) sprite.width,(float) sprite.height};


}
 
void Item::rotateItem(){
    ImageRotate(&img, 90);
}

void Item::drawItem(){
    DrawTexture(sprite,pos.x,pos.y,bluee);
}

void Item::drawItem(int posX, int posY){
    DrawTexture(sprite,posX,posY,bluee);
}
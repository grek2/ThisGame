#include "raylib.h"
#include "Player.h"
#include <string>

using namespace std;

Color shadowBlue {0,50, 50, 100};
Color personblue {100, 130, 135, 255};

Player::Player(string localPathIn, Vector2 startingPos, int health){
    localPath = localPathIn;
    img = LoadImage(localPathIn.c_str());
    ImageResizeNN(&img, 100, 100);
    
    sprite=LoadTextureFromImage(img);
    pos = startingPos;
    girdPos =
    speed = {100.0,100.0};
    hitBox={pos.x, pos.y, (float) sprite.width,(float) sprite.height};
    health = health;
    points=0;
}




void Player::drawPlayer(){
    DrawTexture(sprite, girdPos.x*100, girdPos.y*100, personblue);
}

PlayerDirection Player::detectKeys(vector<vector<int>>& map){
    
    if(IsKeyPressed(KEY_W)){
        return PlayerDirection::NORTH;
    }
    if(IsKeyPressed(KEY_S)){
        return PlayerDirection::SOUTH;
    }
    if(IsKeyPressed(KEY_A)){
        //ImageFlipHorizontal(&img);
        return PlayerDirection::WEST;
    }
    if(IsKeyPressed(KEY_D)){
        return PlayerDirection::EAST;
    }
    return PlayerDirection::NONE;
}

void Player::movePlayer(PlayerDirection dir){
    switch (dir){
        case PlayerDirection::NORTH:
            girdPos.y-=1;
            //pos.y-=speed.y;
            break;
        case PlayerDirection::SOUTH:
            girdPos.y+=1;
            break;
        case PlayerDirection::EAST:
            girdPos.x+=1;
            break;
        case PlayerDirection::WEST:
            girdPos.x-=1;
            break;
        default:
            break;
    }
}

void Player::teleportPlayer(Vector2 startingPos)
{
    girdPos = startingPos;
}
#include "stuff.h"

using namespace std;

int gridAccess1(vector<vector<int>>& map, int x, int y)
{
    if (x >= 0 && y >= 0 && static_cast<size_t>(x) < map.size() && static_cast<size_t>(y) < map[x].size()) {
        return map[x][y];
    }
    return -1;
}

Fish::Fish(string localPathIn, Vector2 startingPos, int health, FishDirection startingDirection){
    localPath = localPathIn;
    img = LoadImage(localPathIn.c_str());
    ImageResizeNN(&img, 100, 100);
    moveState = startingDirection;
    sprite=LoadTextureFromImage(img);
    gridPos = startingPos;
    speed = {100.0,100.0};
    health = 10;
    hitBox={pos.x, pos.y, (float) sprite.width,(float) sprite.height};
}




void Fish::drawFish(){
    //cout<<gridPos.x<<", "<<gridPos.y<<endl;
    DrawTexture(sprite, gridPos.x*100, gridPos.y*100, WHITE);
}

void Fish::fishUpdate(vector<vector<int>>& mapData)
{
    int northOfFish=gridAccess1(mapData, gridPos.x, gridPos.y-1);
    int southOFFish = gridAccess1(mapData, gridPos.x, gridPos.y+1);
    int eastOfFish = gridAccess1(mapData, gridPos.x+1, gridPos.y);
    int westOfFish = gridAccess1(mapData, gridPos.x-1, gridPos.y);
    int fishPosNum = gridAccess1(mapData, gridPos.x, gridPos.y);
    if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_A)||IsKeyPressed(KEY_S)||IsKeyPressed(KEY_D))
    {
        if (moveState == FishDirection::EAST)
        {
            //cout<<"east"<<endl;
            if (gridAccess1(mapData, gridPos.x+1, gridPos.y) != -1 && gridAccess1(mapData, gridPos.x+1, gridPos.y) != 1){
                fishMove(FishDirection::EAST);
            }
            else {
                moveState = FishDirection::WEST;
            }

        }

        else if (moveState == FishDirection::WEST)
        {
            //cout<<"west"<<endl;
            if (gridAccess1(mapData, gridPos.x-1, gridPos.y) != -1 && gridAccess1(mapData, gridPos.x-1, gridPos.y) != 1){
                fishMove(FishDirection::WEST);
            }
            else {
                moveState = FishDirection::EAST;
            }

        }
        
        else if (moveState == FishDirection::SOUTH)
        {
            //cout<<"south"<<endl;
            if (gridAccess1(mapData, gridPos.x, gridPos.y+1) != -1 && gridAccess1(mapData, gridPos.x, gridPos.y+1) != 1){
                //cout<<gridPos.x<<", "<<gridPos.y<<": southGood"<<endl;
                fishMove(FishDirection::SOUTH);
            }
            else {
                moveState = FishDirection::NORTH;
                //cout<<gridPos.x<<", "<<gridPos.y<<": SouthBad"<<endl;
            }

        }

        else if (moveState == FishDirection::NORTH)
        {
            //cout<<"north"<<endl;
            if (gridAccess1(mapData, gridPos.x, gridPos.y-1) != -1 && gridAccess1(mapData, gridPos.x, gridPos.y-1) != 1){
                //cout<<gridPos.x<<", "<<gridPos.y<<": northGood"<<endl;
                fishMove(FishDirection::NORTH);
            }
            else {
                moveState = FishDirection::SOUTH;
                //cout<<gridPos.x<<", "<<gridPos.y<<": northBad"<<endl;
            }

        }
    }
}


void Fish::fishMove(FishDirection dir){
    switch (dir){
        case FishDirection::NORTH:
            gridPos.y-=1;
            break;
        case FishDirection::SOUTH:
            gridPos.y+=1;
            break;
        case FishDirection::EAST:
            gridPos.x+=1;
            break;
        case FishDirection::WEST:
            gridPos.x-=1;
            break;
        default:
            break;
    }
}

void Fish::teleportFish(Vector2 startingPos)
{
    gridPos = startingPos;
}
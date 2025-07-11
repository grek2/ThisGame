#include "stuff.h"

#ifndef FISH_H
#define FISH_H

using namespace std;


enum class FishDirection{
    NORTH, SOUTH, EAST, WEST, NONE
};


class Fish{
private:
    string localPath;
    Texture2D sprite;
    Image img;
    Vector2 pos;
    Vector2 speed;
    Rectangle hitBox;
    int health;
    int points;
    FishDirection moveState;

public:
    Vector2 gridPos;
    Fish(string localPathIn, Vector2 startingPos, int health, FishDirection startingDirection);

    void fishMove(FishDirection dir);

    void fishUpdate(vector<vector<int>>& mapData);

    void drawFish();

    void teleportFish(Vector2 startingPos);

};

#endif
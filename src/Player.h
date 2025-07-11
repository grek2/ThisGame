#include <string>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

enum class PlayerDirection{
    NORTH, SOUTH, EAST, WEST, NONE
};

class Player{
private:
    string localPath;
    Texture2D sprite;
    Image img;
    Vector2 pos;
    
    Vector2 speed;
    Rectangle hitBox;
    int health;
    int points;

public:
    Vector2 girdPos;
    Player(string localPathIn, Vector2 startingPos, int health);

    void movePlayer(PlayerDirection dir);

    PlayerDirection detectKeys(vector<vector<int>>& map);

    void drawPlayer();

    void useItem();

    void teleportPlayer(Vector2 startingPos);

};

#endif
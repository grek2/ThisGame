#include "stuff.h"

int gridAccess(vector<vector<int>>& map, int x, int y)
{
    if (x > -1 && y > -1 && x < map.size() && y < map[x].size())
    {
        return map[x][y];
    }
    return -1;
}

int randomLevel() 
{
    srand(time(NULL));
    return (rand() % 6) + 1;         
}

int distanceMan(int x1, int x2, int y1, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

void movement(Player& player, vector<vector<int>>& map){
    PlayerDirection playerDirection = player.detectKeys(map); 
        int playerx= player.girdPos.x; 
        int playery= player.girdPos.y;

        /*
        cout<<endl;
        cout<<"  "<<gridAccess(mapData, playerx, playery-1)<<endl;
        cout<<gridAccess(mapData, playerx-1, playery)<<" "<<gridAccess(mapData, playerx, playery)<<" "<<gridAccess(mapData, playerx+1, playery)<<endl;
        cout<<"  "<<gridAccess(mapData, playerx, playery+1)<<endl;
        */


        if (playerDirection == PlayerDirection::NORTH) 
        {
            if (gridAccess(map, playerx, playery-1) != 1 && gridAccess(map, playerx, playery-1) != -1)
            {
                player.movePlayer(playerDirection);             
            }
        }
        else if (playerDirection == PlayerDirection::SOUTH)
        {
            if (gridAccess(map, playerx, playery+1) != 1 && gridAccess(map, playerx, playery+1) != -1)
            {
                player.movePlayer(playerDirection);
            }
        }
        else if (playerDirection == PlayerDirection::EAST)
        {
            if (gridAccess(map, playerx+1, playery) != 1 && gridAccess(map, playerx+1, playery) != -1)
            {
                player.movePlayer(playerDirection);
            }
        }
        else if (playerDirection == PlayerDirection::WEST)
        {
            if (gridAccess(map, playerx-1, playery) != 1 && gridAccess(map, playerx-1, playery) != -1)
            {
                player.movePlayer(playerDirection);
            }
        }

}

vector<vector<int>> transpose(const vector<vector<int>>& ogGrid) {


    int rows = ogGrid.size();
    int columns = ogGrid[0].size();

    // Create new grid
    vector<vector<int>> newGrid(columns, std::vector<int>(rows));

    // transfer to the new one
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            newGrid[j][i] = ogGrid[i][j];
        }
    }
    return newGrid;
}

int main()
{
    int attempts = 0;
    int steps = 0;
    int level = randomLevel();

    int START_X; 
    int START_Y;
    int END_X; 
    int END_Y;

    //original level positions- start 2, 6; end 5, 0
    //CHANGE THESE TO CHANGE START AND END POSITIONS

    switch (level)
    {
        case 1:
            START_X = 2; 
            START_Y = 6;
            END_X = 5; 
            END_Y = 0;
            break;
        case 2:
            START_X = 0; 
            START_Y = 4;
            END_X = 7; 
            END_Y = 3;
            break;
        case 3:
            START_X = 7; 
            START_Y = 6;
            END_X = 1; 
            END_Y = 6;
            break;
        case 4:
            START_X = 4; 
            START_Y = 2;
            END_X = 1; 
            END_Y = 0;
            break;
        case 5:
            START_X = 7; 
            START_Y = 0;
            END_X = 1; 
            END_Y = 4;
            break;
        case 6:
            START_X = 2; 
            START_Y = 2;
            END_X = 2; 
            END_Y = 0;

    }


    //MAP DATA THING
    ifstream inputFile("MapData/mapData"+to_string(level)+".txt"); // Assuming mapData.txt exists

    if (!inputFile.is_open()) {

        cerr << "Error: Could not open file!" << endl;
        return 1;

    }

    vector<vector<int>> mapData; //map data a vectorvector
    string line;

    while (getline(inputFile, line)) {

        vector<int> row; 
        istringstream iss(line);
        int value;

        while (iss >> value) {

            row.push_back(value);

        }

        mapData.push_back(row);
    }
    inputFile.close();

    mapData=transpose(mapData);

//-------------------------------------



    //Init stage
    int screenWidth = 800;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Game");

    Player player1("reasources/helmetSprite.png",(Vector2) {100,600}, 10);
    //Player player2("reasources/maskedSprite.png",(Vector2) {200,100}, 10);

    int h=0;
    int i=0;
    double j=0; 

    Tile bgTile1("reasources/floorTile1.png", (Vector2) {0, 0});
    Tile bgTile2("reasources/floorTile2.png", (Vector2) {0, 0});
    Tile bgTile3("reasources/floorTile3.png", (Vector2) {0, 0});

    
    //Fish fish1("reasources/fish1.png", (Vector2) {3, 5}, 10, FishDirection::EAST);
    //Fish fish2("reasources/fish2.png", (Vector2) {1, 4}, 10, FishDirection::SOUTH);
    

    Wall wall("reasources/wall.png", (Vector2) {0, 0});
    Item whirlpool("reasources/whirlpool.png", (Vector2) {0, 0});
    Wall rock("reasources/weirdrock.png", (Vector2) {0, 0});

    vector<Wall> walls;
    vector<Item> whirlpools;
    vector<Wall> rocks;
    vector<Fish> fishes;

    for(int k=0; k<mapData.size(); k++)
        {
            for (int l=0; l<mapData[k].size(); l++)
            {
                if (mapData[k][l]==1)
                {
                    walls.push_back({"reasources/wall.png", (Vector2) {(float) k*100, (float) l*100}});
                    //cout<<k<<", "<<l<<endl;
                }
                if (mapData[k][l]==2)
                {
                    whirlpools.push_back({"reasources/whirlpool.png", (Vector2) {(float) k*100, (float) l*100}});
                }
                if (mapData[k][l]==3)
                {
                    player1.teleportPlayer((Vector2) {(float) k, (float) l});
                }
                if (mapData[k][l]==4)
                {
                    rocks.push_back({"reasources/plant.png", (Vector2) {(float) k*100, (float) l*100}});
                }
                if (mapData[k][l]==5)
                {
                    //fish1.teleportFish((Vector2) {(float) k, (float) l});
                    fishes.push_back({"reasources/fish2.png", (Vector2) {(float) k, (float) l}, 10, FishDirection::EAST});
                }
                if (mapData[k][l]==6)
                {
                    //fish1.teleportFish((Vector2) {(float) k, (float) l});
                    fishes.push_back({"reasources/fish1.png", (Vector2) {(float) k, (float) l}, 10, FishDirection::NORTH});
                }
            }
        }
    


    /*
    int randX = random1to8()*100;
    int randY = random1to8()*100;
    */

    SetTargetFPS(60);

    while(WindowShouldClose() == false) {

        //Update Staged
        
        if (END_X!=player1.girdPos.x || END_Y!=player1.girdPos.y)
            {
                movement(player1,mapData);
            }
        

        ClearBackground(WHITE);
        //Drawing stage
        BeginDrawing();
        //ClearBackground(DARKBLUE);


            for (h = j; h < 800; h+=300)
            {
                for (i = 0; i < 800; i+=100)
                {
                    bgTile1.drawTile(h, i);
                    bgTile2.drawTile(h+100, i);
                    bgTile3.drawTile(h+200, i);
                }
            }

            
            if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_A)||IsKeyPressed(KEY_S)||IsKeyPressed(KEY_D))
            {
                j-=50;
                h = 0;
                i = 0;
                whirlpool.rotateItem();
                if (END_X!=player1.girdPos.x || END_Y!=player1.girdPos.y)
                {
                    steps++;
                }
            }
            
    
        player1.drawPlayer();
        //player2.drawPlayer();
        //whirlpool.drawItem(randX, randY);
        for(auto wall : walls)
            {
                wall.drawWall();
            }

        for(auto whirlpool : whirlpools)
            {
                whirlpool.drawItem();
            }
        
        for(auto rock : rocks)
            {
                rock.drawWall(); // it is not a rock nor a wall, its a plant
            } 
    
        
        Color darkness {0, 0, 0, 130};
        //Color lightness {255, 255, 255, 130};
        
        for(int gridX=0; gridX<mapData.size(); gridX++){
            for(int grid=0; grid<mapData[gridX].size(); grid++){
                if(distanceMan(gridX,player1.girdPos.x,grid,player1.girdPos.y)>2)
                {
                    DrawRectangle(gridX*100,grid*100,100,100,darkness);
                    DrawRectangle(gridX*100,grid*100,100,100,darkness);
                    DrawRectangle(gridX*100,grid*100,100,100,darkness);

                }
                if(distanceMan(gridX,player1.girdPos.x,grid,player1.girdPos.y)>1)
                {
                    DrawRectangle(gridX*100,grid*100,100,100,darkness);
                    DrawRectangle(gridX*100,grid*100,100,100,darkness);
                }
                if(distanceMan(gridX,player1.girdPos.x,grid,player1.girdPos.y)>0)
                {
                    DrawRectangle(gridX*100,grid*100,100,100,darkness);
                } 
        
            }

        }

        for(auto& fish : fishes)
            {
                fish.fishUpdate(mapData);
                fish.drawFish();

                if (fish.gridPos.x==player1.girdPos.x && fish.gridPos.y==player1.girdPos.y)
                {
                    DrawRectangle(0, 0, 800, 800, {255, 100, 100, 200});

                    player1.teleportPlayer((Vector2) {(float) START_X, (float) START_Y});
                    attempts++;
                    //fish.teleportFish((Vector2) {(float) k, (float) l});
                }
            }

        if (END_X==player1.girdPos.x && END_Y==player1.girdPos.y)
                {
                
                    string statsDisplay = "Steps: " + to_string(steps) + "\nDeaths: " + to_string(attempts);
                    DrawText("Level Solved", 15, 298, 120, GREEN);
                    DrawText(statsDisplay.c_str(), 15, 400, 50, GREEN);

                }
 
        EndDrawing();
    }
    cout<<"Steps: "<<steps<<endl<<"Attempts: "<<attempts<<endl;
    CloseWindow();
    CloseAudioDevice();
}
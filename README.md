# Made a small game
Dont look at the code too much

if you want to compile without vs code:
g++ -o main src/main.cpp fish.cpp grid.cpp items.cpp Player.cpp tiles.cpp wall.cpp -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -g -O0 C:/raylib/raylib/src/raylib.rc.data -I. -IC:/raylib/raylib/src -IC:/raylib/raylib/src/external -L. -LC:/raylib/raylib/src -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -DPLATFORM_DESKTOP

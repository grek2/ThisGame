# I made a small puzzlish game.

Might make it more polished, might not.
If you keep randomly dying that's not a bug you're just bad at the game.

I used some C graphics library and not win32 because unlike SOMEONE I like to sleep sometimes and not being in pain most of the time.


if you want to compile it without vs code:
g++ -o main src/main.cpp fish.cpp grid.cpp items.cpp Player.cpp tiles.cpp wall.cpp -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -g -O0 C:/raylib/raylib/src/raylib.rc.data -I. -IC:/raylib/raylib/src -IC:/raylib/raylib/src/external -L. -LC:/raylib/raylib/src -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -DPLATFORM_DESKTOP


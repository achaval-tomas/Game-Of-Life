# Game-Of-Life

Another one of my first few projects in C++, lots of improvements to be done.

My version of Conway's well-known Game of Life made in C++ and SDL.

Play with (Windows, mingw32)
````
start bin/release/main
````
Compile with
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I C:/SDL2-w64/include && g++ *.o -o bin/release/main -s -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````

Keybinds:
Left click to add living cells, right click to remove them. Space to start/pause and C to clear the screen and reset generations.

https://github.com/achaval-tomas/Game-Of-Life/assets/134091945/513f4cde-1585-4f72-a573-585aaec7fa1d



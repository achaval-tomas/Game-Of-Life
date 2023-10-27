# Game-Of-Life

Another one of my first few projects in C++, lots of improvements to be done.

My version of Conway's well-known Game of Life made in C++ and SDL.

Play with (Windows)
````
start bin/release/main
````
Compile (on Windews, with mingw) with
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I /bin/release && g++ *.o -o bin/release/main -s -L /bin/release -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````
Play with (Linux)
````
./bin/release/mainLinux
````
Compile (on Linux) with
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I /bin/release && g++ *.o -o bin/release/mainLinux -s -L /bin/release -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````

Keybinds:
Left click to add living cells, right click to remove them. Space to start/pause and C to clear the screen and reset generations.

https://github.com/achaval-tomas/Game-Of-Life/assets/134091945/513f4cde-1585-4f72-a573-585aaec7fa1d

**Necessary Libraries are included in bin/release. If this doesn't work for you, you may need to [Download and install SDL](https://www.libsdl.org/) and/or [mingw](https://www.mingw-w64.org/)**

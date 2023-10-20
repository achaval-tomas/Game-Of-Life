# Game-Of-Life

Another one of my first few projects in C++, lots of improvements to be done.

My version of Conway's well-known Game of Life made in C++ and SDL.

Play with
````
g++ -o play -I include src/*.cpp \`sdl2-config --cflags --libs\` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
./play
````

Keybinds:
Left click to add living cells, right click to remove them. Space to start/pause and C to clear the screen and reset generations.

https://github.com/achaval-tomas/Game-Of-Life/assets/134091945/513f4cde-1585-4f72-a573-585aaec7fa1d

Install necessary libraries:
````
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-mixer-dev
````


#pragma once

#define SIZE 10

#define DEAD false
#define LIVE true

#define GOLD       			 {255, 202,  24, 255}
#define ROUND_FONT			 "res/fonts/roundedFont.ttf"

#define GENERATION_PARAMS renderer, ROUND_FONT, 30, "#generations: " + std::to_string(generations) + "  ", GOLD
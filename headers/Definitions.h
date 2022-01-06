#pragma once
#include <string>

const int SCREEN_WIDTH = 17*48;
const int SCREEN_HEIGHT = 16*48; 
const std::string APP_NAME = "F-Pusher";

const float SPRITE_SCALE = 0.75f;
const int SOURCE_SPRITE_SIZE = 64;
const int TILE_SIZE = 48;

const int MAX_LEVEL = 105;

const float ANIMATION_TIME=0.2;


enum Direction
{
	NO_DIRECTION,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

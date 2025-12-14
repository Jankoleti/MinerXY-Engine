#include "t_time.hpp"
#include <SDL3/SDL.h>

float deltaTime = 0.0f;
float currentTime = 0.0f;
float lastTime = 0.0f;


void ProcessDeltaTime()
{
	currentTime = SDL_GetTicks();
	deltaTime = (currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;
}
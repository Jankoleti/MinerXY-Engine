#pragma once
#include <SDL3/SDL.h>



class Texture
{
public:
	Texture(SDL_Surface* surface, SDL_Renderer* renderer);
	SDL_Texture* sdlTexture;
	SDL_FRect rect;
	float textureWidth, textureHeight;
	
	~Texture()
	{
		delete sdlTexture;
	}
};
#include "r_files.hpp"



std::map<std::string, std::unique_ptr<Texture>> TEXTURES = {};


void CreateTextureFromBMP(const char* name, const char* file){
	SDL_Surface* surface = SDL_LoadBMP(file);
	TEXTURES.emplace(name, std::unique_ptr<Texture>(new Texture(surface, renderer)));
}

void DeleteTexture(char* name)
{
	if (TEXTURES.find(name) != TEXTURES.end())
	{
		delete TEXTURES.at(name).get();
		TEXTURES.at(name).reset();
		TEXTURES.erase(name);
	}
}

#include "r_texture.hpp"




Texture::Texture(SDL_Surface* surface, SDL_Renderer* renderer)
{
	sdlTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!sdlTexture) {
        SDL_Log("Couldn't create static texture: %s", SDL_GetError());
    }
    textureWidth = surface->w;
    textureHeight = surface->h;
    SDL_DestroySurface(surface);
}
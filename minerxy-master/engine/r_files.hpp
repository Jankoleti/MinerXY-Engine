#pragma once
#include <map>
#include <SDL3/SDL.h>
#include <memory>
#include <string>
#include "r_texture.hpp"
#include "render.hpp"

extern std::map<std::string, std::unique_ptr<Texture>> TEXTURES;



void CreateTextureFromBMP(const char* name, const char* file);
void DeleteTexture(char* name);
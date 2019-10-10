#pragma once
#include<list>
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool Start();

	bool CleanUp();

	SDL_Texture* const Load(const char* path);
	void const RenderTexture(SDL_Rect rect);

private:
	std::list<SDL_Texture*> textures;
};
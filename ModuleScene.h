#include "Module.h"
#include "Globals.h"

#include "SDL/include/SDL.h"

class Moduletextures;

class ModuleScene : public Module {

public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	bool Start();

	//void AddTexture(const char* path);

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	bool CleanUp();

private:
	SDL_Rect background;
	SDL_Rect player;
	SDL_Texture* graphics;


};
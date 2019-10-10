#pragma once
#include "Module.h"
#include "Globals.h"

#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

class ModuleAudio : public Module {

public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool Start();

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	bool CleanUp();

private:
	Mix_Music* test_sound;
};
#include "Application.h"
#include "ModuleAudio.h"



ModuleAudio::ModuleAudio() {
	
}

ModuleAudio::~ModuleAudio() {

}

bool ModuleAudio::Init(){
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	test_sound = NULL;

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;

	test_sound = Mix_LoadMUS("the_grid.mp3");
	
	return true;

}

bool ModuleAudio::Start() {
	return true;
}

update_status ModuleAudio::PreUpdate() {
	return UPDATE_CONTINUE;
}


update_status ModuleAudio::Update() {
	return UPDATE_CONTINUE;
}

update_status ModuleAudio::PostUpdate() {
	return UPDATE_CONTINUE;
}


bool ModuleAudio::CleanUp() {

	Mix_FreeMusic(test_sound);

	return true;
}


#include "Application.h"
#include "ModuleAudio.h"
#include <iostream>



ModuleAudio::ModuleAudio() {
	
}

ModuleAudio::~ModuleAudio() {

}

bool ModuleAudio::Init(){
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	test_sound = nullptr;

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;

	//Set the music
	test_sound = Mix_LoadMUS("../SDL_mixer/musik.wav");
	if (test_sound == NULL)
		std::cout << "No sound found" << std::endl;
	else
		std::cout << "Sound found" << std::endl;

	return true;

}

bool ModuleAudio::Start() {

	//Play it on the first frame
	Mix_PlayMusic(test_sound, -1);
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

	//Free the music
	//Mix_FreeMusic(test_sound); //This explodes hard

	return true;
}


#include "Globals.h"
#include "Application.h"

#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


ModuleScene::ModuleScene() {

}

ModuleScene::~ModuleScene() {

}

void ModuleScene::AddTexture(const char* path) {
	App->textures->Load(path);

}

bool ModuleScene::Init() {

	AddTexture("SDL_image/hackerman.jpg");

	return true;
}

bool ModuleScene::Start() {

	return true;
}

update_status ModuleScene::PreUpdate() {

	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update() {

	App->textures->RenderTextures();
	

	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate() {

	SDL_RenderPresent(App->renderer->renderer);
	return UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp() {
	return true;
}
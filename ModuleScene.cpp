#include "Globals.h"
#include "Application.h"
#include <iostream>
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


ModuleScene::ModuleScene() {

	player.x = 170;
	player.y = 100;
	player.w = 300;
	player.h = 300;

}

ModuleScene::~ModuleScene() {





}

//void ModuleScene::AddTexture(const char* path) {
	//

//}
bool ModuleScene::Init() {

	//AddTexture();
	graphics = App->textures->Load("../SDL_image/hackerman.png");

	if (graphics == NULL)
		std::cout << "No texture" << std::endl;
	else
		std::cout << "Texture loaded" << std::endl;

	return true;
}

bool ModuleScene::Start() {

	return true;
}

update_status ModuleScene::PreUpdate() {

	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update() {

	App->textures->RenderTexture(player);

	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate() {

	return UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp() {
	return true;
}
#pragma once

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleScene;

class Application
{
public:

	Application();
	~Application();

	bool Init();

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	bool CleanUp();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleScene* scene;

private:

	std::list<Module*> modules;

};

extern Application* App; //could be changed, all the methods on the modules could be static
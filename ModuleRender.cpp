#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"

ModuleRender::ModuleRender()
{
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);
	
	if(renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::Start() {
	return true;
}

// TODO 5: Now that we have PreUpdate/PostUpdate/Update move things around so we can render :)

//Clear
update_status ModuleRender::PreUpdate() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	return UPDATE_CONTINUE;
}

//Set the stuff we want to draw
update_status ModuleRender::Update()
{

	SDL_SetRenderDrawColor(renderer, 125, 125, 125, 0);


	for (int i = 0; i < 20; ++i) {
		SDL_RenderDrawLine(renderer, 0, 45*i, SCREEN_WIDTH, 45*i);
	}

	SDL_SetRenderDrawColor(renderer, 125, 0, 125, 0);

	for (int i = 0; i < 20; ++i) {
		SDL_RenderDrawLine(renderer, 45 * i, 0, 45 * i * 2, SCREEN_HEIGHT);
	}

	return UPDATE_CONTINUE;
}

//Actually draw the stuff
update_status ModuleRender::PostUpdate() {
	SDL_RenderPresent(renderer);

	return UPDATE_CONTINUE;

}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	if(section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	if(SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

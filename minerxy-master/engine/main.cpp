#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "game_central.hpp"



SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;



SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    SDL_SetAppMetadata("Example Renderer Primitives", "1.0", "com.example.renderer-primitives");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("MinerXY", windowWidth, windowHeight, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    Init();

    return SDL_APP_CONTINUE; 
}


SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->key.scancode == SDL_SCANCODE_W)
    {
        mainCamera.transform.position.y -= 10;
    }
    if (event->key.scancode == SDL_SCANCODE_S)
    {
        mainCamera.transform.position.y += 10;
    }
    if (event->key.scancode == SDL_SCANCODE_A)
    {
        mainCamera.transform.position.x -= 10;
    }
    if (event->key.scancode == SDL_SCANCODE_D)
    {
        mainCamera.transform.position.x += 10;
    }
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void* appstate)
{
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, SDL_ALPHA_OPAQUE); 
    SDL_RenderClear(renderer); 

    MainLoop();
    
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
}


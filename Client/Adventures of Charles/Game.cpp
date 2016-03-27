#include <iostream>
#include "Game.h"
#include "World.h"
#include "Input.h"
#include <SDL_image.h>

const int FRAMERATE = 300;

bool Game::running = false;
SDL_Window* Game::window = NULL;
SDL_Surface* Game::screen = NULL;
SDL_Renderer* Game::renderer = NULL;
SDL_Event Game::sdlEvent;
float Game::deltaTime;

int Game::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Could not init SDL" << std::endl;
        return -1;
    }
    else {
        window = SDL_CreateWindow("AOC", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
        //screen = SDL_GetWindowSurface(window);
    }

    if(SDLNet_Init() < 0) {
        std::cout << "Could not init SDL_net " << SDLNet_GetError() << std::endl;
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        std::cout << "Could not create renderer " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);

    if(!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Could not init SDL_image " << IMG_GetError() << std::endl;
        return -1;
    }

    running = true;
    World::Init();
    std::cout << "Game initialized" << std::endl;
    return 0;
}

int Game::Quit() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    SDL_Quit();
    return 0;
}

void Game::Loop() {
    int lastTime = SDL_GetTicks();
    deltaTime = 0.02f;
    while(running) {
        int startTime = SDL_GetTicks();
        int frameTime = startTime - lastTime;
        if(frameTime >= 16) {
            Input();

            //Logic
            World::Update();

            deltaTime = frameTime / 60.0f;
            lastTime = startTime;
        }
        Render();
        SDL_Delay(1);
    }
    Quit();
}

void Game::Input() {
    while(SDL_PollEvent(&sdlEvent) != 0) {
        if(sdlEvent.type == SDL_QUIT) {
            running = false;
        }
        if(sdlEvent.type == SDL_KEYDOWN) {
            switch(sdlEvent.key.keysym.sym)
            {
            case SDLK_w:

                Input::WPressed = true;
                break;
            case SDLK_s:
                std::cout << SDL_GetTicks() << std::endl;
                Input::SPressed = true;
                break;
            case SDLK_d:
                Input::DPressed = true;
                break;
            case SDLK_a:
                Input::APressed = true;
                break;
            }
        }
        if(sdlEvent.type == SDL_KEYUP) {
            switch(sdlEvent.key.keysym.sym)
            {
            case SDLK_w:
                Input::WPressed = false;
                break;
            case SDLK_s:
                Input::SPressed = false;
                break;
            case SDLK_d:
                Input::DPressed = false;
                break;
            case SDLK_a:
                Input::APressed = false;
                break;
            }
        }
    }
}

void Game::Render() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect* rect = new SDL_Rect();
    rect->x = 100;
    rect->y = 100;
    rect->w = 400;
    rect->h = 400;
    //SDL_FillRect(screen, rect, SDL_MapRGB(screen->format, 0xA3, 0x20, 0x40));
    //SDL_RenderFillRect(renderer, rect);
    World::Draw();
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(renderer);
}
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <eigen3/Eigen/Dense>
#include <iostream>
using namespace std;
using Eigen::Vector2f;
/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
Uint64 lstime = 0;
struct myobj {
  SDL_FRect rect;
  Vector2f velovity;
  Vector2f acceleration;
} mr;
float acc = 0.002;
const int windowwidth = 1000;
const int windowhight = 600;
/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Couldn't initialize SDL!",
                             SDL_GetError(), NULL);
    return SDL_APP_FAILURE;
  }

  if (!SDL_CreateWindowAndRenderer("examples/CATEGORY/NAME", windowwidth,
                                   windowhight, 0, &window, &renderer)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             "Couldn't create window/renderer!", SDL_GetError(),
                             NULL);
    return SDL_APP_FAILURE;
  }
  mr.rect.x = 2;
  mr.rect.y = 2;
  mr.rect.h = 100;
  mr.rect.w = 100;
  return SDL_APP_CONTINUE; /* carry on with the program! */
}
/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS; /* end the program, reporting success to the OS. */
  }
  if (event->type == SDL_EVENT_KEY_DOWN) {
    if (event->key.scancode == SDL_SCANCODE_W) {
      mr.acceleration(1) = -acc;
    }
  }
  if (event->type == SDL_EVENT_KEY_UP) {
    if (event->key.scancode == SDL_SCANCODE_W) {
      mr.acceleration(1) = 0;
    }
  }
  if (event->type == SDL_EVENT_KEY_DOWN) {
    if (event->key.scancode == SDL_SCANCODE_A) {
      mr.acceleration(0) = -acc;
    }
  }
  if (event->type == SDL_EVENT_KEY_UP) {
    if (event->key.scancode == SDL_SCANCODE_A) {
      mr.acceleration(0) = 0;
    }
  }
  if (event->type == SDL_EVENT_KEY_DOWN) {
    if (event->key.scancode == SDL_SCANCODE_S) {
      mr.acceleration(1) = +acc;
    }
  }
  if (event->type == SDL_EVENT_KEY_UP) {
    if (event->key.scancode == SDL_SCANCODE_S) {
      mr.acceleration(1) = 0;
    }
  }
  if (event->type == SDL_EVENT_KEY_DOWN) {
    if (event->key.scancode == SDL_SCANCODE_D) {
      mr.acceleration(0) = acc;
    }
  }
  if (event->type == SDL_EVENT_KEY_UP) {
    if (event->key.scancode == SDL_SCANCODE_D) {
      mr.acceleration(0) = 0;
    }
  }

  cout << event->type << endl;
  return SDL_APP_CONTINUE; /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);
  Uint64 nowtime = SDL_GetTicks();

  mr.rect.x += mr.velovity(0) * (nowtime - lstime);

  mr.rect.y += mr.velovity(1) * (nowtime - lstime);
  mr.velovity += mr.acceleration * (nowtime - lstime);
  cout << mr.rect.x << ' ' << mr.rect.y << endl;
  if (mr.rect.x < 0)
    mr.rect.x = windowwidth;

  if (mr.rect.x > windowwidth)
    mr.rect.x = 0;
  if (mr.rect.y < 0)
    mr.rect.y = windowhight;

  if (mr.rect.y > windowhight)
    mr.rect.y = 0;
  lstime = nowtime;

  SDL_RenderRect(renderer, &mr.rect);
  SDL_RenderFillRect(renderer, &mr.rect);
  SDL_RenderPresent(renderer);
  return SDL_APP_CONTINUE; /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  /* SDL will clean up the window/renderer for us. */
}

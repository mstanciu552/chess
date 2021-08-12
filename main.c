#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define BOARD_IMPLEMENTATION
#include "board.h"

#define PIECES_IMPLEMENTATION
#include "pieces.h"

int main(void) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error initializing SDL: %s\n", SDL_GetError());
  }

  SDL_Window *win = SDL_CreateWindow("Chess", 
                                      SDL_WINDOWPOS_CENTERED, 
                                      SDL_WINDOWPOS_CENTERED, 
                                      640, 640, 0);

  if (win == NULL) {
    exit(1);
    return 1;
  }

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    printf("Image library could not be loaded!");
    exit(2);
  }

  SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect *rectangles = create_rect_array();

  SDL_Surface *surface = load_surface("./templates/black_bishop.png");
  if (surface == NULL) exit(3);

  create_board(rend, rectangles);
  SDL_RenderPresent(rend); // Show what's drawn to the screen

  load_texture(rend, surface, rectangles);

  bool running = true;
  while(running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;
      }
    }
  }
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  IMG_Quit();
  SDL_Quit();
  return 0;
}

#ifndef BOARD_H_
#define BOARD_H_

#include <SDL2/SDL.h>

#define WIDTH  8
#define HEIGHT 8
#define SIZE   80

SDL_Rect *create_rect_array();
void create_board(SDL_Renderer *rend, SDL_Rect *rectangles);

#endif // BOARD_H_

#ifdef BOARD_IMPLEMENTATION

SDL_Rect *create_rect_array() {
  SDL_Rect *rectangles = (SDL_Rect*) malloc(8 * 8 * sizeof(SDL_Rect));
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      SDL_Rect r = {.x = i * SIZE, .y = j * SIZE, .w = SIZE, .h= SIZE};
      rectangles[i + j * WIDTH] = r;
    }
  }
  return rectangles;
}

void create_board(SDL_Renderer *rend, SDL_Rect *rectangles) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j+=2) {
      if (i % 2 == 0) {
        SDL_SetRenderDrawColor(rend, 119, 149, 87, 255);
        SDL_RenderFillRect(rend, &rectangles[j + i * HEIGHT]);

        SDL_SetRenderDrawColor(rend, 237, 237, 208, 255);
        SDL_RenderFillRect(rend, &rectangles[j + 1 + i * HEIGHT]);
      } else {
        SDL_SetRenderDrawColor(rend, 237, 237, 208, 255);
        SDL_RenderFillRect(rend, &rectangles[j + i * HEIGHT]);

        SDL_SetRenderDrawColor(rend, 119, 149, 87, 255);
        SDL_RenderFillRect(rend, &rectangles[j + 1 + i * HEIGHT]);
      }
    }
  }
}

#endif // BOARD_IMPLEMENTATION

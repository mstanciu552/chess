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

  SDL_Window *win = SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, 0);

  if (win == NULL) exit(1);

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    printf("Image library could not be loaded!");
    exit(1);
  }

  SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect *rectangles = create_rect_array();

  create_board(rend, rectangles);
  SDL_RenderPresent(rend); // Show what's drawn to the screen

  Piece white_pawn = new_piece(load_surface("./templates/white_pawn.png"), calculate_square(calc_start(PAWN, WHITE)), PAWN, WHITE);
  Piece white_rook = new_piece(load_surface("./templates/white_rook.png"), calculate_square(calc_start(ROOK, WHITE)), ROOK, WHITE);
  Piece white_bishop = new_piece(load_surface("./templates/white_bishop.png"), calculate_square(calc_start(BISHOP, WHITE)), BISHOP, WHITE);
  Piece white_knight = new_piece(load_surface("./templates/white_knight.png"), calculate_square(calc_start(KNIGHT, WHITE)), KNIGHT, WHITE);
  Piece white_king = new_piece(load_surface("./templates/white_king.png"), calculate_square(calc_start(KING, WHITE)), KING, WHITE);
  Piece white_queen = new_piece(load_surface("./templates/white_rook.png"), calculate_square(calc_start(QUEEN, WHITE)), QUEEN, WHITE);

  load_texture(rend, white_pawn);
  load_texture(rend, white_rook);
  load_texture(rend, white_bishop);
  load_texture(rend, white_knight);
  load_texture(rend, white_king);
  load_texture(rend, white_queen);

  // TODO Add events for moving pieces
  bool running = true;
  SDL_Event event;
  while(running) {
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

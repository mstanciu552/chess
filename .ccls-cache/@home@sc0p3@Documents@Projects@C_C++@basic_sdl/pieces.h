#ifndef PIECES_H_
#define PIECES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdbool.h>

typedef char* string;
typedef struct Position { int x, y; } Position;

typedef enum Pieces {
  PAWN,
  BISHOP,
  KNIGHT,
  ROOK,
  QUEEN,
  KING
} Pieces;

typedef enum Color {
  WHITE,
  BLACK
} Color;

typedef struct Piece {
  Pieces type;
  Position pos;
  SDL_Surface *surface;
  Color color;
} Piece;

bool is_valid(Piece piece, Position pos);
SDL_Surface *load_surface(string path);
void load_texture(SDL_Renderer *rend, SDL_Surface *surface, SDL_Rect *rectangles);
Piece add_piece_to_object(SDL_Surface *surface, Pieces type, Color color);
SDL_Texture **get_pieces_texture_array(SDL_Renderer *rend, string path);

#endif // PIECES_H_

#ifdef PIECES_IMPLEMENTATION

bool is_valid(Piece piece, Position pos) {
  switch(piece.type) {
    case PAWN:
      break;
    case BISHOP:
      break;
    case ROOK:
      break;
    case KNIGHT:
      break;
    case QUEEN:
      break;
    case KING:
      break;
    default:
      printf("Invalid Piece");
      return false;
  }
  return false;
}

SDL_Surface *load_surface(string path) {
  SDL_Surface *loaded_surface = IMG_Load(path);

  if (loaded_surface == NULL) {
    printf("Error loading surface");
    return NULL;
  }

  return loaded_surface;
}

void load_texture(SDL_Renderer *rend, SDL_Surface *surface, SDL_Rect *rectangles) {
  SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, surface);
  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

  SDL_FreeSurface(surface);
  SDL_QueryTexture(texture, NULL, NULL, &rectangles[0].w, &rectangles[0].h);
  SDL_RenderCopy(rend, texture, &rectangles[0], &rectangles[0]);

  SDL_RenderPresent(rend); // Show what's drawn to the screen
  /* SDL_Delay(1000 / 60); */

  SDL_DestroyTexture(texture);
}

Piece add_piece_to_object(SDL_Surface *surface, Pieces type, Color color) {
  Piece p = {.type = type, .pos = {.x = 0, .y = 0}, .surface = surface, .color = color};
  return p;
}

SDL_Texture **get_pieces_texture_array(SDL_Renderer *rend, string path) {
  SDL_Texture **textures = (SDL_Texture**) malloc(16 * sizeof(SDL_Texture*));
  SDL_Surface *surface = load_surface(path);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
  SDL_Rect box = {.x = 0, .y = 0, .w = 70, .h = 70};

  SDL_RenderCopy(rend, tex, &box, NULL);
  SDL_RenderPresent(rend);

  textures[0] = tex;

  return textures;
}
 
#endif // PIECES_IMPLEMENTATION

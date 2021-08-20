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
void load_texture(SDL_Renderer *rend, Piece piece);
Piece new_piece(SDL_Surface *surface, Position position, Pieces type, Color color);
void move_piece(Piece piece, Position position);
Position calculate_square(Position position);
Position calc_start(Pieces type, Color color);

#endif // PIECES_H_

#ifdef PIECES_IMPLEMENTATION

// TODO Finish checking based on type
// Position start from 0 and end at 7 for both rows and columns
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

void load_texture(SDL_Renderer *rend,  Piece piece) {
  SDL_Rect rectangle = {.x = piece.pos.x, .y = piece.pos.y, .w = 80, .h = 80};

  SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, piece.surface);
  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

  SDL_FreeSurface(piece.surface);
  SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);
  SDL_RenderCopy(rend, texture, NULL, &rectangle);

  SDL_RenderPresent(rend); // Show what's drawn to the screen

  SDL_DestroyTexture(texture);
}

Piece new_piece(SDL_Surface *surface, Position position, Pieces type, Color color) {
  Piece p = {.type = type, .pos = position, .surface = surface, .color = color};
  return p;
}

void move_piece(Piece piece, Position position) {
  piece.pos = position;
}

Position calculate_square(Position position) {
  Position normalized_position = {.x = 0, .y = 0};

  normalized_position.x = (position.x * 80) + 12;
  normalized_position.y = (position.y * 80) + 12;

  return normalized_position;
}

// TODO Finish this for all piece types
Position calc_start(Pieces type, Color color) {
  Position position = {.x = 0, .y = 0};

  switch(type) {
    case PAWN:
      if (color == WHITE) { 
        position.x = 0;
        position.y = 1;
      }
      else if (color == BLACK) {
        position.x = 0;
        position.y = 6;
      }
      break;
    case BISHOP:
      if (color == WHITE) { 
        position.x = 2;
        position.y = 0;
      }
      else if (color == BLACK) {
        position.x = 3;
        position.y = 7;
      }
      break;
    case ROOK:
      if (color == WHITE) { 
        position.x = 0;
        position.y = 0;
      }
      else if (color == BLACK) {
        position.x = 0;
        position.y = 7;
      }
      break;
    case KNIGHT:
      if (color == WHITE) { 
        position.x = 1;
        position.y = 0;
      }
      else if (color == BLACK) {
        position.x = 0;
        position.y = 6;
      }
      break;
    case QUEEN:
      if (color == WHITE) { 
        position.x = 3;
        position.y = 0;
      }
      else if (color == BLACK) {
        position.x = 0;
        position.y = 6;
      }
      break;
    case KING:
      if (color == WHITE) { 
        position.x = 4;
        position.y = 0;
      }
      else if (color == BLACK) {
        position.x = 0;
        position.y = 6;
      }
      break;
    default:
      printf("Invalid Piece");
      break;
    }
  return position;
}
 
#endif // PIECES_IMPLEMENTATION

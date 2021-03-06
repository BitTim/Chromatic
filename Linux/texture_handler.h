#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path);

class Sprite
{
public:
  SDL_Texture *texture;

  bool animated = false;
  int frames = 1;
  int speed = 100;

  Sprite(SDL_Renderer *renderer, std::string path)
  {
    texture = load_texture(renderer, path);
  }

  Sprite(SDL_Renderer *renderer, std::string path, int num_frames, int init_speed)
  {
    animated = true;
    frames = num_frames;
    speed = init_speed;

    texture = load_texture(renderer, path);
  }
};

SDL_Surface *texture_loader;
Sprite *sprite_loader;
std::vector<Sprite> texture_atlas;
std::vector<Sprite> gfx_atlas;

SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path)
{
  texture_loader = IMG_Load(path.c_str());

  if(texture_loader == NULL)
  {
    texture_loader = IMG_Load("data/textures/missing.png");
    if(texture_loader == NULL)
    {
      printf("Error 201: Could not load Texure, %s", IMG_GetError());
      return NULL;
    }
  }

  return SDL_CreateTextureFromSurface(renderer, texture_loader);
}

int load_textures(SDL_Renderer* renderer)
{
  sprite_loader = new Sprite(renderer, "data/textures/player_white_idle.png", 12, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/player_white_running_right.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/player_white_running_left.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/player_red_idle.png", 12, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/player_red_running_right.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/player_red_running_left.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/player_green_idle.png", 12, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/player_green_running_right.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/player_green_running_left.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/player_blue_idle.png", 12, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/player_blue_running_right.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/player_blue_running_left.png", 8, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/brick_white.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/brick_red.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/brick_green.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/brick_blue.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;
  
  sprite_loader = new Sprite(renderer, "data/textures/unlock_red.png", 16, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/unlock_green.png", 16, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/unlock_blue.png", 16, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/door_green_top.png", 4, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/door_green_bottom.png", 4, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/red_green_brick.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/red_blue_brick.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/green_blue_brick.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/red_green_blue_brick.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/spike_white.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/spike_red.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/spike_green.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/spike_blue.png");
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/heal_small.png", 1, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  sprite_loader = new Sprite(renderer, "data/textures/missing.png", 1, 75);
  texture_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  SDL_FreeSurface(texture_loader);
  return 0;
}

int load_gfx(SDL_Renderer* renderer)
{
  sprite_loader = new Sprite(renderer, "data/gfx/edge_blur.png");
  gfx_atlas.push_back(*sprite_loader);
  delete sprite_loader;

  SDL_FreeSurface(texture_loader);
  return 0;
}

#endif // TEXTURE_HANDLER_H

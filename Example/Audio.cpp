#include <SDL.h>
#include <SDL2/SDL_mixer.h>
#include <spdlog/spdlog.h>

#include "../Source/Engine/Audio/Mod.hpp"

int main()
{
    spdlog::info("Running");
    if(SDL_Init(SDL_INIT_AUDIO) < 0)
		return -1;

	Hx::Audio::Audio audio;
    Hx::Audio::Music music("Assets/ImperialMarch.ogg");
    music.Play();

    while (Mix_PlayingMusic())
    {
    }
}
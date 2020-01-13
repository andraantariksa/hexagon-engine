#pragma once

#include <stdexcept>

#include <SDL2/SDL_mixer.h>

namespace Hx { namespace Audio {
    class Music
    {
        private:
        Mix_Music* MusicInstance;

        public:
        Music(const char* filePath)
        {
            this->MusicInstance = Mix_LoadMUS(filePath);
            if (this->MusicInstance == nullptr)
            {
                throw std::runtime_error("Can't load the music");
            }
        }

        ~Music()
        {
            Mix_FreeMusic(this->MusicInstance);
        }

        inline void Play(int loop = 1)
        {
            if (Mix_PlayMusic(this->MusicInstance, loop))
            {
                throw std::runtime_error("Can't play the music");
            }
        }

        static inline bool IsPlaying()
        {
            return Mix_PlayingMusic();
        }
    };
} }
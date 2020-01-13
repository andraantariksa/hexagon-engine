
#pragma once

#include <stdexcept>

#include <SDL2/SDL_mixer.h>

namespace Hx { namespace Audio {

    enum class Channel
    {
        Mono = 1,
        Stereo = 2,
    };

    class Audio
    {
        public:
        Audio(int frequency = 22050, Channel channel = Channel::Mono, int chunksize = 4096)
        {
            Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, (int) channel, chunksize);
        }

        ~Audio()
        {
            Mix_CloseAudio();
        }
    };

} }
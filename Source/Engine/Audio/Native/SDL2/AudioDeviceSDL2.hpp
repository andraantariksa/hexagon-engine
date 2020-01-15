#pragma once
#include "../../IAudioDevice.hpp"
#include <SDL.h>
#include <vector>

namespace Hx { namespace Audio { namespace Native {

	class AudioDeviceSDL2 : public IAudioDevice
	{
	public:
		AudioDeviceSDL2();
		~AudioDeviceSDL2();

		void Create(uint8 numChannels, uint32 bufferSize, float sampleRate) override;

	private:
		SDL_AudioDeviceID Device;

	private:
		static void SDLAudioCallback(void* userdata, Uint8* stream, int len);
		static bool IsDeviceCreated;
	};

}}}

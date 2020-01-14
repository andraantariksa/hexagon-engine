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
		MixerChannel* CreateAudioMixerChannel(float initialVolume) override;
		void AddMixerChannel(MixerChannel* mixerChannel) override;
		void AttachMixerChannel(uint32 slot, MixerChannel* mixerChannel) override;
		void DetachMixerChannel(uint32 slot) override;
		void ReserveMixerChannel(uint32 numSlots) override;

	private:
		SDL_AudioDeviceID Device;
		std::vector<MixerChannel*> MixerChannels;

	private:
		static void SDLAudioCallback(void* userdata, Uint8* stream, int len);
		static bool IsDeviceCreated;
	};

}}}

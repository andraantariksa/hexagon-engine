#include "AudioEngineSDL2.hpp"
#include <memory>

namespace Hx { namespace Audio { namespace Native {

	AudioDeviceSDL2::AudioDeviceSDL2()
		: Device(0)
	{
		IsDeviceCreated = true;
	}

	AudioDeviceSDL2::~AudioDeviceSDL2()
	{
		IsDeviceCreated = false;
	}

	void AudioDeviceSDL2::Create(uint8 numChannels, uint32 bufferSize, float sampleRate)
	{
		SDL_AudioSpec desired = { 0 };
		SDL_AudioSpec obtained;

		desired.callback = SDLAudioCallback;
		desired.channels = numChannels;
		desired.format = AUDIO_F32;
		desired.samples = (Uint16)bufferSize;
		desired.freq = (int)sampleRate;

		Device = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);
	}

	MixerChannel* AudioDeviceSDL2::CreateAudioMixerChannel(float initialVolume)
	{
		return nullptr;
	}

	void AudioDeviceSDL2::AddMixerChannel(MixerChannel* mixerChannel)
	{
	}

	void AudioDeviceSDL2::AttachMixerChannel(uint32 slot, MixerChannel* mixerChannel)
	{
	}

	void AudioDeviceSDL2::DetachMixerChannel(uint32 slot)
	{
	}

	void AudioDeviceSDL2::ReserveMixerChannel(uint32 numSlots)
	{
	}

	// ---------------------------------------------------------------------------------------
	void AudioDeviceSDL2::SDLAudioCallback(void* userdata, Uint8* stream, int len)
	{
	}

	// ---------------------------------------------------------------------------------------
	bool AudioDeviceSDL2::IsDeviceCreated = false;

}}}

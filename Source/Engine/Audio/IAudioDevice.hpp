#pragma once

#include "../Types.hpp"
#include "MixerChannel.hpp"

namespace Hx { namespace Audio {

	struct HX_NOVTABLE IAudioDevice
	{
		virtual ~IAudioDevice() { }

		virtual void Create(uint8 numChannels, uint32 bufferSize, float sampleRate) = 0;
		virtual MixerChannel* CreateAudioMixerChannel(float initial) = 0;
		virtual void AddMixerChannel(MixerChannel* mixerChannel) = 0;
		virtual void AttachMixerChannel(uint32 slot, MixerChannel* mixerChannel) = 0;
		virtual void DetachMixerChannel(uint32 slot) = 0;
		virtual void ReserveMixerChannel(uint32 numSlots) = 0;
	};

}}

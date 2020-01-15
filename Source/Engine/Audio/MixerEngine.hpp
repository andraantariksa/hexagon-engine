#pragma once

#include "MixerChannel.hpp"

namespace Hx { namespace Audio {

	class MixerEngine
	{
	public:
		MixerEngine()
		{
		}

		~MixerEngine()
		{
		}

		void AddMixerChannel(MixerChannel* mixerChannel);
		void AttachMixerChannel(uint32 slot, MixerChannel* mixerChannel);
		void DetachMixerChannel(uint32 slot);
		void ReserveMixerChannel(uint32 numSlots);
		void ProcessAudio(uint8 numChannels, uint32 numSamples, float** audioBlock, float sampleRate);
	};

}}

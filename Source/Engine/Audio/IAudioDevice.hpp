#pragma once

#include "../Types.hpp"
#include "MixerChannel.hpp"

namespace Hx { namespace Audio {

	struct HX_NOVTABLE IAudioDevice
	{
		virtual ~IAudioDevice() { }

		virtual void Create(uint8 numChannels, uint32 bufferSize, float sampleRate) = 0;
	};

}}

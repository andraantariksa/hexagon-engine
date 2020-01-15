#pragma once

#include "../Types.hpp"
#include "../Math/Math.hpp"

namespace Hx { namespace Audio {

	class MixerChannel
	{
	public:
		MixerChannel();

		virtual ~MixerChannel();

		void AddAudioStream();
		void ProcessAudio(uint8 numChannels, uint32 numSamples, float** audioBlock, float sampleRate);

		void SetVolume(float newVolume);

		float GetVolume();

	private:
		float Volume;
	};

}}

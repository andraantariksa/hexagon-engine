#pragma once

#include "../Types.hpp"
#include "../Math/Math.hpp"

namespace Hx { namespace Audio {

	class MixerChannel
	{
	public:
		MixerChannel();

		virtual ~MixerChannel();

		virtual void AddAudioStream() { };

		virtual void SetVolume(float newVolume);

		virtual float GetVolume();

	protected:
		float Volume;
	};

}}

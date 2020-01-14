#pragma once

#include "MixerChannel.hpp"

namespace Hx { namespace Audio {

	MixerChannel::MixerChannel()
		: Volume(0.0f)
	{
	}

	MixerChannel::~MixerChannel()
	{
	}

	void MixerChannel::SetVolume(float newVolume)
	{
		this->Volume = (newVolume < 0.0f) ? 0.0f : newVolume;
	}

	float MixerChannel::GetVolume()
	{
		return Volume;
	}

}}

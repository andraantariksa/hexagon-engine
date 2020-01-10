#pragma once

#include "../../Types.hpp"
#include "../Event.hpp"
#include <string>

namespace Hx { namespace Window { namespace Native {

	struct INativeWindow
	{
		virtual ~INativeWindow() {}

		virtual void SetTitle(const std::string& title) = 0;
		virtual void SetPosition(int32 x, int32 y) = 0;
		virtual void SetSize(int32 width, int32 height) = 0;
		virtual void SetWidth(int32 width) = 0;
		virtual void SetHeight(int32 height) = 0;

		virtual bool PollEvent(Hx::Window::Event& e) = 0;

		virtual const std::string& GetTitle() const = 0;
		virtual int32 GetPositionX() = 0;
		virtual int32 GetPositionY() = 0;
		virtual int32 GetWidth() = 0;
		virtual int32 GetHeight() = 0;
		virtual const char* GetBackendAPI() const = 0;
	};

}}}

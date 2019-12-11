#pragma once

#include <string>

namespace Hx { namespace Window { namespace Native {

	struct INativeWindow
	{
		virtual ~INativeWindow() {}

		virtual void SetTitle(const std::string& title) = 0;
		virtual void SetPosition(int x, int y) = 0;
		virtual void SetSize(int width, int height) = 0;
		virtual void SetWidth(int width) = 0;
		virtual void SetHeight(int height) = 0;

		virtual const std::string& GetTitle() const = 0;
		virtual int GetPositionX() = 0;
		virtual int GetPositionY() = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
	};

}}}

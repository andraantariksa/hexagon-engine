#pragma once

#include <string>
#include "../../Types.h"

namespace Hx { namespace Window { namespace Native {

	struct INativeWindow
	{
		virtual ~INativeWindow() {}

		virtual void SetTitle(const std::string& title) = 0;
		virtual void SetPosition(Int32 x, Int32 y) = 0;
		virtual void SetSize(Int32 width, Int32 height) = 0;
		virtual void SetWidth(Int32 width) = 0;
		virtual void SetHeight(Int32 height) = 0;

		virtual const std::string& GetTitle() const = 0;
		virtual Int32 GetPositionX() = 0;
		virtual Int32 GetPositionY() = 0;
		virtual Int32 GetWidth() = 0;
		virtual Int32 GetHeight() = 0;
	};

}}}

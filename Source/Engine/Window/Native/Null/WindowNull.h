#pragma once

#include "../INativeWindow.h"

namespace Hx { namespace Window { namespace Native { namespace Null {

	class WindowNull : public INativeWindow
	{
	public:
		WindowNull();
		~WindowNull();

		void SetTitle(const std::string& title) override;
		void SetPosition(Int32 x, Int32 y) override;
		void SetSize(Int32 width, Int32 height) override;
		void SetWidth(Int32 width) override;
		void SetHeight(Int32 height) override;

		const std::string& GetTitle() const override;
		Int32 GetPositionX() override;
		Int32 GetPositionY() override;
		Int32 GetWidth() override;
		Int32 GetHeight() override;
	};

} } } }

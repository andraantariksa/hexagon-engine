#pragma once

#include "../INativeWindow.h"

namespace Hx { namespace Window { namespace Native { namespace Null {

	class WindowNull : public INativeWindow
	{
	public:
		WindowNull();
		~WindowNull();

		void SetTitle(const std::string& title) override;
		void SetPosition(int32 x, int32 y) override;
		void SetSize(int32 width, int32 height) override;
		void SetWidth(int32 width) override;
		void SetHeight(int32 height) override;

		const std::string& GetTitle() const override;
		int32 GetPositionX() override;
		int32 GetPositionY() override;
		int32 GetWidth() override;
		int32 GetHeight() override;
	};

} } } }

#pragma once

#include "../INativeWindow.h"
#include <SDL.h>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	class WindowSDL2 : public INativeWindow
	{
	public:
		WindowSDL2(Int32 width, Int32 height, const std::string& title, Int32 posX, Int32 posY);
		WindowSDL2(const WindowSDL2&) = delete;
		~WindowSDL2();

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

	private:
		void Initialize(int w, int h, int x, int y);

	private:
		std::string mWindowTitle;
		SDL_Window* mNativeHandle;
	};

}}}}

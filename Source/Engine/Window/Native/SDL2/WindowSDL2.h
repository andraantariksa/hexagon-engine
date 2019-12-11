#pragma once

#include "../INativeWindow.h"
#include <SDL.h>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	class WindowSDL2 : public INativeWindow
	{
	public:
		WindowSDL2(int width, int height, const std::string& title, int posX, int posY);
		WindowSDL2(const WindowSDL2&) = delete;
		~WindowSDL2();

		void SetTitle(const std::string& title) override;
		void SetPosition(int x, int y) override;
		void SetSize(int width, int height) override;
		void SetWidth(int width) override;
		void SetHeight(int height) override;

		const std::string& GetTitle() const override;
		int GetPositionX() override;
		int GetPositionY() override;
		int GetWidth() override;
		int GetHeight() override;

	private:
		void Initialize(int w, int h, int x, int y);

	private:
		std::string WindowTitle;
		SDL_Window* NativeHandle;
	};

}}}}

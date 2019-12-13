#pragma once

#include "../INativeWindow.h"
#include <SDL.h>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	class WindowSDL2 : public INativeWindow
	{
	public:
		WindowSDL2(int32 width, int32 height, const std::string& title, int32 posX, int32 posY);
		WindowSDL2(const WindowSDL2&) = delete;
		~WindowSDL2();

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
		const char* GetBackendAPI() const override;

	private:
		void Initialize(int32 w, int32 h, int32 x, int32 y);

	private:
		std::string WindowTitle;
		SDL_Window* NativeHandle;

		static const char* BackendAPI;
	};

}}}}

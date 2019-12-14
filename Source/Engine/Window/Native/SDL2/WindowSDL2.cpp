#include "WindowSDL2.h"

#include <stdexcept>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	WindowSDL2::WindowSDL2(int32 width, int32 height, const std::string& title, int32 posX, int32 posY)
		: WindowTitle(title)
	{
		Initialize(width, height, posX, posY);
	}

	WindowSDL2::~WindowSDL2()
	{
		SDL_DestroyWindow(this->NativeHandle);
	}

	void WindowSDL2::SetTitle(const std::string& title)
	{
		this->WindowTitle = title;
		SDL_SetWindowTitle(this->NativeHandle, this->WindowTitle.c_str());
	}

	void WindowSDL2::SetPosition(int32 x, int32 y)
	{
		SDL_SetWindowPosition(
			this->NativeHandle,
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y
		);
	}

	void WindowSDL2::SetSize(int32 width, int32 height)
	{
		SDL_SetWindowSize(
			this->NativeHandle,
			width,
			height
		);
	}
	void WindowSDL2::SetWidth(int32 width)
	{
		int32 h;
		SDL_GetWindowSize(this->NativeHandle, nullptr, &h);
		SDL_SetWindowSize(this->NativeHandle, width, h);
	}

	void WindowSDL2::SetHeight(int32 height)
	{
		int32 w;
		SDL_GetWindowSize(this->NativeHandle, &w, nullptr);
		SDL_SetWindowSize(this->NativeHandle, w, height);
	}

	const std::string& WindowSDL2::GetTitle() const
	{
		return this->WindowTitle;
	}

	int32 WindowSDL2::GetPositionX()
	{
		int32 x;
		SDL_GetWindowPosition(this->NativeHandle, &x, nullptr);
		return x;
	}

	int32 WindowSDL2::GetPositionY()
	{
		int32 y;
		SDL_GetWindowPosition(this->NativeHandle, nullptr, &y);
		return y;
	}

	int32 WindowSDL2::GetWidth()
	{
		int32 w;
		SDL_GetWindowSize(this->NativeHandle, &w, nullptr);
		return w;
	}

	int32 WindowSDL2::GetHeight()
	{
		int32 h;
		SDL_GetWindowSize(this->NativeHandle, nullptr, &h);
		return h;
	}

	const char* WindowSDL2::GetBackendAPI() const
	{
		return WindowSDL2::BackendAPI;
	}

	SDL_Window* WindowSDL2::GetNativeHandle()
	{
		return this->NativeHandle;
	}

	void WindowSDL2::Initialize(int32 w, int32 h, int32 x, int32 y)
	{
		/*
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
			throw std::runtime_error(std::string("ERROR: SDL_Init failed ") + std::string(SDL_GetError()));
		*/
		
		this->NativeHandle = SDL_CreateWindow(
			this->WindowTitle.c_str(),
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y,
			w,
			h,
			SDL_WINDOW_OPENGL
		);

		if (!this->NativeHandle)
			throw std::runtime_error("ERROR: Cannot initialize window!");

		SDL_ShowWindow(this->NativeHandle);
	}

	const char* WindowSDL2::BackendAPI = "SDL2";

}}}}

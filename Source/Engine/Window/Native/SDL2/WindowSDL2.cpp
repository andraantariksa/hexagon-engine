#include "WindowSDL2.h"

#include <stdexcept>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	WindowSDL2::WindowSDL2(int width, int height, const std::string& title,
		int posX, int posY) :
		WindowTitle(title)
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

	void WindowSDL2::SetPosition(int x, int y)
	{
		SDL_SetWindowPosition(
			this->NativeHandle,
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y
		);
	}

	void WindowSDL2::SetSize(int width, int height)
	{
		SDL_SetWindowSize(
			this->NativeHandle,
			width,
			height
		);
	}

	void WindowSDL2::SetWidth(int width)
	{
		int height;
		SDL_GetWindowSize(this->NativeHandle, nullptr, &height);
		SDL_SetWindowSize(this->NativeHandle, width, height);
	}

	void WindowSDL2::SetHeight(int height)
	{
		int width;
		SDL_GetWindowSize(this->NativeHandle, &width, nullptr);
		SDL_SetWindowSize(this->NativeHandle, width, height);
	}

	const std::string& WindowSDL2::GetTitle() const
	{
		return this->WindowTitle;
	}

	int WindowSDL2::GetPositionX()
	{
		int x;
		SDL_GetWindowPosition(this->NativeHandle, &x, nullptr);
		return x;
	}

	int WindowSDL2::GetPositionY()
	{
		int y;
		SDL_GetWindowPosition(this->NativeHandle, nullptr, &y);
		return y;
	}

	int WindowSDL2::GetWidth()
	{
		int width;
		SDL_GetWindowSize(this->NativeHandle, &width, nullptr);
		return width;
	}

	int WindowSDL2::GetHeight()
	{
		int height;
		SDL_GetWindowSize(this->NativeHandle, nullptr, &height);
		return height;
	}

	void WindowSDL2::Initialize(int w, int h, int x, int y)
	{
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

}}}}

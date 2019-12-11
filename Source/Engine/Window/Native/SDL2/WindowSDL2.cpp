#include "WindowSDL2.h"

#include <stdexcept>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	WindowSDL2::WindowSDL2(Int32 width, Int32 height, const std::string& title,
		Int32 posX, Int32 posY) :
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

	void WindowSDL2::SetPosition(Int32 x, Int32 y)
	{
		SDL_SetWindowPosition(
			this->NativeHandle,
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y);
	}

	void WindowSDL2::SetSize(Int32 width, Int32 height)
	{
		SDL_SetWindowSize(
			this->NativeHandle,
			width,
			height);
	}

	void WindowSDL2::SetWidth(Int32 width)
	{
		Int32 h;
		SDL_GetWindowSize(this->NativeHandle, nullptr, &h);
		SDL_SetWindowSize(this->NativeHandle, width, h);
	}

	void WindowSDL2::SetHeight(Int32 height)
	{
		Int32 w;
		SDL_GetWindowSize(this->NativeHandle, &w, nullptr);
		SDL_SetWindowSize(this->NativeHandle, w, height);
	}

	const std::string& WindowSDL2::GetTitle() const
	{
		return this->WindowTitle;
	}

	Int32 WindowSDL2::GetPositionX()
	{
		Int32 x;
		SDL_GetWindowPosition(this->NativeHandle, &x, nullptr);
		return x;
	}

	Int32 WindowSDL2::GetPositionY()
	{
		Int32 y;
		SDL_GetWindowPosition(this->NativeHandle, nullptr, &y);
		return y;
	}

	Int32 WindowSDL2::GetWidth()
	{
		Int32 w;
		SDL_GetWindowSize(this->NativeHandle, &w, nullptr);
		return w;
	}

	Int32 WindowSDL2::GetHeight()
	{
		Int32 h;
		SDL_GetWindowSize(this->NativeHandle, nullptr, &h);
		return h;
	}

	void WindowSDL2::Initialize(Int32 w, Int32 h, Int32 x, Int32 y)
	{
		this->NativeHandle = SDL_CreateWindow(
			this->WindowTitle.c_str(),
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y,
			w,
			h,
			SDL_WINDOW_OPENGL);

		if (!this->NativeHandle)
			throw std::runtime_error("ERROR: Cannot initialize window!");

		SDL_ShowWindow(this->NativeHandle);
	}

}}}}

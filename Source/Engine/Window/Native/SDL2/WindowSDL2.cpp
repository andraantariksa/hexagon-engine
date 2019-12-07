#include "WindowSDL2.h"

#include <iostream>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	WindowSDL2::WindowSDL2(Int32 width, Int32 height, const std::string& title, Int32 posX, Int32 posY)
		: mWindowTitle(title)
	{
		Initialize(width, height, posX, posY);
	}

	WindowSDL2::~WindowSDL2()
	{
		SDL_DestroyWindow(mNativeHandle);
	}

	void WindowSDL2::SetTitle(const std::string& title)
	{
		mWindowTitle = title;
		SDL_SetWindowTitle(mNativeHandle, mWindowTitle.c_str());
	}

	void WindowSDL2::SetPosition(Int32 x, Int32 y)
	{
		SDL_SetWindowPosition(
			mNativeHandle,
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y);
	}

	void WindowSDL2::SetSize(Int32 width, Int32 height)
	{
		SDL_SetWindowSize(
			mNativeHandle,
			width,
			height);
	}

	void WindowSDL2::SetWidth(Int32 width)
	{
		Int32 h;
		SDL_GetWindowSize(mNativeHandle, nullptr, &h);
		SDL_SetWindowSize(mNativeHandle, width, h);
	}

	void WindowSDL2::SetHeight(Int32 height)
	{
		Int32 w;
		SDL_GetWindowSize(mNativeHandle, &w, nullptr);
		SDL_SetWindowSize(mNativeHandle, w, height);
	}

	const std::string& WindowSDL2::GetTitle() const
	{
		return mWindowTitle;
	}

	Int32 WindowSDL2::GetPositionX()
	{
		Int32 x;
		SDL_GetWindowPosition(mNativeHandle, &x, nullptr);
		return x;
	}

	Int32 WindowSDL2::GetPositionY()
	{
		Int32 y;
		SDL_GetWindowPosition(mNativeHandle, nullptr, &y);
		return y;
	}

	Int32 WindowSDL2::GetWidth()
	{
		Int32 w;
		SDL_GetWindowSize(mNativeHandle, &w, nullptr);
		return w;
	}

	Int32 WindowSDL2::GetHeight()
	{
		Int32 h;
		SDL_GetWindowSize(mNativeHandle, nullptr, &h);
		return h;
	}

	void WindowSDL2::Initialize(Int32 w, Int32 h, Int32 x, Int32 y)
	{
		mNativeHandle = SDL_CreateWindow(
			mWindowTitle.c_str(),
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y,
			w,
			h,
			SDL_WINDOW_OPENGL);

		if (!mNativeHandle)
			throw std::exception("ERROR: Cannot initialize window!");

		SDL_ShowWindow(mNativeHandle);
	}

}}}}

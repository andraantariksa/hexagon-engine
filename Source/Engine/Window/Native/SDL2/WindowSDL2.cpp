#include "WindowSDL2.h"

#include <iostream>

namespace Hx { namespace Window { namespace Native { namespace SDL2 {

	WindowSDL2::WindowSDL2(int32 width, int32 height, const std::string& title, int32 posX, int32 posY)
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

	void WindowSDL2::SetPosition(int32 x, int32 y)
	{
		SDL_SetWindowPosition(
			mNativeHandle,
			(x < 0) ? SDL_WINDOWPOS_CENTERED : x,
			(y < 0) ? SDL_WINDOWPOS_CENTERED : y);
	}

	void WindowSDL2::SetSize(int32 width, int32 height)
	{
		SDL_SetWindowSize(
			mNativeHandle,
			width,
			height);
	}

	void WindowSDL2::SetWidth(int32 width)
	{
		int32 h;
		SDL_GetWindowSize(mNativeHandle, nullptr, &h);
		SDL_SetWindowSize(mNativeHandle, width, h);
	}

	void WindowSDL2::SetHeight(int32 height)
	{
		int32 w;
		SDL_GetWindowSize(mNativeHandle, &w, nullptr);
		SDL_SetWindowSize(mNativeHandle, w, height);
	}

	const std::string& WindowSDL2::GetTitle() const
	{
		return mWindowTitle;
	}

	int32 WindowSDL2::GetPositionX()
	{
		int32 x;
		SDL_GetWindowPosition(mNativeHandle, &x, nullptr);
		return x;
	}

	int32 WindowSDL2::GetPositionY()
	{
		int32 y;
		SDL_GetWindowPosition(mNativeHandle, nullptr, &y);
		return y;
	}

	int32 WindowSDL2::GetWidth()
	{
		int32 w;
		SDL_GetWindowSize(mNativeHandle, &w, nullptr);
		return w;
	}

	int32 WindowSDL2::GetHeight()
	{
		int32 h;
		SDL_GetWindowSize(mNativeHandle, nullptr, &h);
		return h;
	}

	void WindowSDL2::Initialize(int32 w, int32 h, int32 x, int32 y)
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

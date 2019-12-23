#include "WindowSDL2.h"
#include "KeymapSDL2.h"

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

	bool WindowSDL2::PollEvent(Hx::Window::Event& e)
	{
		SDL_Event sdlEvent;
		bool ret;

		ret = SDL_PollEvent(&sdlEvent);

		switch (sdlEvent.type)
		{
		case SDL_WINDOWEVENT:
			switch (sdlEvent.window.event)
			{
			case SDL_WINDOWEVENT_SHOWN:
				e.Type = EventType::WindowShow;
				break;
			case SDL_WINDOWEVENT_HIDDEN:
				e.Type = EventType::WindowHide;
				break;
			case SDL_WINDOWEVENT_MOVED:
				e.Type = EventType::WindowMove;
				e.WindowMoveEvent.X = sdlEvent.window.data1;
				e.WindowMoveEvent.Y = sdlEvent.window.data2;
				break;
			case SDL_WINDOWEVENT_CLOSE:
				e.Type = EventType::WindowClose;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				e.Type = EventType::WindowResize;
				e.WindowMoveEvent.X = sdlEvent.window.data1;
				e.WindowMoveEvent.Y = sdlEvent.window.data2;
				break;
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				e.Type = EventType::WindowResize;
				e.WindowMoveEvent.X = sdlEvent.window.data1;
				e.WindowMoveEvent.Y = sdlEvent.window.data2;
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				e.Type = EventType::WindowMinimize;
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				e.Type = EventType::WindowMaximize;
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				e.Type = EventType::WindowLostFocus;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				e.Type = EventType::WindowGainFocus;
				break;
			}
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			{
				uint16 mod = sdlEvent.key.keysym.mod;
				e.Type = EventType((uint32)EventType::KeyDown + sdlEvent.type - SDL_KEYDOWN);
				e.KeyboardEvent.KeyCode = KeymapSDL2[sdlEvent.key.keysym.scancode];
				e.KeyboardEvent.LControlKey = bool((mod & KMOD_LCTRL) >> 6);
				e.KeyboardEvent.LShiftKey = bool(mod & KMOD_LSHIFT);
				e.KeyboardEvent.LAltKey = bool((mod & KMOD_LALT) >> 8);
				e.KeyboardEvent.RControlKey = bool((mod & KMOD_RCTRL) >> 7);
				e.KeyboardEvent.RShiftKey = bool((mod & KMOD_RSHIFT) >> 1);
				e.KeyboardEvent.RAltKey = bool((mod & KMOD_RALT) >> 9);
				e.KeyboardEvent.ControlKey = bool(e.KeyboardEvent.LControlKey | e.KeyboardEvent.RControlKey);
				e.KeyboardEvent.ShiftKey = bool(e.KeyboardEvent.LShiftKey | e.KeyboardEvent.RShiftKey);
				e.KeyboardEvent.AltKey = bool(e.KeyboardEvent.LAltKey | e.KeyboardEvent.RAltKey);
				e.KeyboardEvent.Repeat = sdlEvent.key.repeat > 0;
				break;
			}
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			e.Type = EventType((uint32)EventType::MouseBtnDown + sdlEvent.type - SDL_MOUSEBUTTONDOWN);
			e.MouseButtonEvent.Button = MouseButton(sdlEvent.button.button);
			e.MouseButtonEvent.Clicks = sdlEvent.button.clicks;
			e.MouseButtonEvent.X = sdlEvent.button.x;
			e.MouseButtonEvent.Y = sdlEvent.button.y;
			break;
		case SDL_MOUSEMOTION:
			e.Type = EventType::MouseMove;
			e.MouseMoveEvent.Buttons = sdlEvent.motion.state;
			e.MouseMoveEvent.X = sdlEvent.motion.x;
			e.MouseMoveEvent.X = sdlEvent.motion.y;
			e.MouseMoveEvent.RelativeX = sdlEvent.motion.xrel;
			e.MouseMoveEvent.RelativeY = sdlEvent.motion.yrel;
			break;
		case SDL_MOUSEWHEEL:
			e.Type = EventType::MouseWheel;
			e.MouseWheelEvent.AmountX = sdlEvent.wheel.x;
			e.MouseWheelEvent.AmountY = sdlEvent.wheel.y;
			e.MouseWheelEvent.Direction = (bool)sdlEvent.wheel.direction;
			break;
		}

		return ret;
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
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
			throw std::runtime_error(std::string("ERROR: SDL_Init failed ") + std::string(SDL_GetError()));
		
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

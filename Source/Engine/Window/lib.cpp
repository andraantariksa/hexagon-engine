#ifdef HEXAGON_ENGINE_WINDOW_LIB
#define HEXAGON_ENGINE_WINDOW_LIB

#include <cstdio>
#include <stdexcept>

#include "Dependencies/SDL2/include/SDL.h"

namespace Window {
	class Window {
	public:
		class Builder;

		Window(char* title, int width, int height, int x_pos = SDL_WINDOWPOS_UNDEFINED, int y_pos = SDL_WINDOWPOS_UNDEFINED, Uint32 window_flag = SDL_WINDOW_OPENGL)
		{
			SDL_Init(SDL_INIT_VIDEO);
			this->window = SDL_CreateWindow(
				title,
				x_pos,
				y_pos,
				width,
				height,
				window_flag
			);

			SDL_Delay(3000);
		}

	private:
		SDL_Window* window;
	};

	class Window::Builder {
	public:
		Builder()
		{
			title = nullptr;
			x_pos = SDL_WINDOWPOS_UNDEFINED;
			y_pos = SDL_WINDOWPOS_UNDEFINED;
			width = -1;
			height = -1;
		}
		
		Builder& SetTitle(char* title)
		{
			this->title = title;
			return *this;
		}

		Builder& SetXStart(int x_pos)
		{
			this->x_pos = x_pos;
			return *this;
		}

		Builder& SetYStart(int y_pos)
		{
			this->y_pos = y_pos;
			return *this;
		}
		
		Builder& SetHeight(int height)
		{
			this->height = height;
			return *this;
		}

		Builder& SetWidth(int width)
		{
			this->width = width;
			return *this;
		}

		Window Build()
		{
			if (this->width < 0 || this->height  < 0)
			{
				throw std::underflow_error("Invalid width or height size");
			}

			return Window(
				this->title,
				this->width,
				this->height,
				this->x_pos,
				this->y_pos
			);
		}

	private:
		char* title;
		int width;
		int height;
		int x_pos;
		int y_pos;
	};
}

#endif

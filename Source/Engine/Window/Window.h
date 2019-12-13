#pragma once

#include <string>
#include "Native/INativeWindow.h"

namespace Hx { namespace Window {

	class Window
	{
	public:
		class Builder;

	public:
		Window(int32 width = 640, int32 height = 480, const std::string& title = "Hexagon Engine", int32 posX = -1, int32 posY = -1);
		~Window();

		void SetTitle(const std::string& str)
		{
			this->NativeWindow->SetTitle(str);
		}

		void SetTitle(const char* title)
		{
			this->NativeWindow->SetTitle(std::string(title));
		}

		void SetPosition(int32 x, int32 y)
		{
			this->NativeWindow->SetPosition(x, y);
		}

		void SetSize(int32 width, int32 height)
		{
			this->NativeWindow->SetSize(width, height);
		}

		void SetWidth(int32 width)
		{
			this->NativeWindow->SetWidth(width);
		}

		void SetHeight(int32 height)
		{
			this->NativeWindow->SetHeight(height);
		}

		const std::string& GetTitle() const
		{
			return this->NativeWindow->GetTitle();
		}

		int32 GetPositionX()
		{
			return this->NativeWindow->GetPositionX();
		}

		int32 GetPositionY()
		{
			return this->NativeWindow->GetPositionY();
		}

		int32 GetWidth()
		{
			return this->NativeWindow->GetWidth();
		}

		int32 GetHeight()
		{
			return this->NativeWindow->GetHeight();
		}

		const char* GetBackendAPI() const
		{
			return this->NativeWindow->GetBackendAPI();
		}

		Native::INativeWindow* GetNative() const
		{
			return this->NativeWindow;
		}

	private:
		Native::INativeWindow* NativeWindow;
	};

	class Window::Builder
	{
	public:
		Builder()
			: Width(640),
			Height(480),
			Title("Hexagon Engine"),
			PosX(-1),
			PosY(-1)
		{
		}

		~Builder()
		{
		}

		Builder& SetTitle(const std::string& title)
		{
			this->Title = title;
			return *this;
		}

		Builder& SetPosition(int32 x, int32 y)
		{
			this->PosX = x;
			this->PosY = y;
			return *this;
		}

		Builder& SetSize(int32 w, int32 h)
		{
			this->Width = w;
			this->Height = h;
			return *this;
		}

		Window Build()
		{
			return Window(this->Width, this->Height, this->Title, this->PosX, this->PosY);
		}

	private:
		int32 Width, Height;
		int32 PosX, PosY;
		std::string Title;
	};


} }

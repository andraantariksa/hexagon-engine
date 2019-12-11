#pragma once

#include <string>
#include "../Types.h"
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
			mNativeWindow->SetTitle(str);
		}

		void SetTitle(const char* title)
		{
			mNativeWindow->SetTitle(std::string(title));
		}

		void SetPosition(int32 x, int32 y)
		{
			mNativeWindow->SetPosition(x, y);
		}

		void SetSize(int32 width, int32 height)
		{
			mNativeWindow->SetSize(width, height);
		}

		void SetWidth(int32 width)
		{
			mNativeWindow->SetWidth(width);
		}

		void SetHeight(int32 height)
		{
			mNativeWindow->SetHeight(height);
		}

		const std::string& GetTitle() const
		{
			return mNativeWindow->GetTitle();
		}

		int32 GetPositionX()
		{
			return mNativeWindow->GetPositionX();
		}

		int32 GetPositionY()
		{
			return mNativeWindow->GetPositionY();
		}

		int32 GetWidth()
		{
			return mNativeWindow->GetWidth();
		}

		int32 GetHeight()
		{
			return mNativeWindow->GetHeight();
		}

	private:
		Native::INativeWindow* mNativeWindow;
	};

	class Window::Builder
	{
	public:
		Builder()
			: mWidth(640),
			mHeight(480),
			mTitle("Hexagon Engine"),
			mPosX(-1),
			mPosY(-1)
		{
		}

		~Builder()
		{
		}

		Builder& SetTitle(const std::string& title)
		{
			mTitle = title;
			return *this;
		}

		Builder& SetPosition(int32 x, int32 y)
		{
			mPosX = x;
			mPosY = y;
			return *this;
		}

		Builder& SetSize(int32 w, int32 h)
		{
			mWidth = w;
			mHeight = h;
			return *this;
		}

		Window Build()
		{
			return Window(mWidth, mHeight, mTitle, mPosX, mPosY);
		}

	private:
		int32 mWidth, mHeight;
		int32 mPosX, mPosY;
		std::string mTitle;
	};

} }

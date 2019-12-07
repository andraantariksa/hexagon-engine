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
		Window(Int32 width = 640, Int32 height = 480, const std::string& title = "Hexagon Engine", Int32 posX = -1, Int32 posY = -1);
		~Window();

		void SetTitle(const std::string& str)
		{
			mNativeWindow->SetTitle(str);
		}

		void SetTitle(const char* title)
		{
			mNativeWindow->SetTitle(std::string(title));
		}

		void SetPosition(Int32 x, Int32 y)
		{
			mNativeWindow->SetPosition(x, y);
		}

		void SetSize(Int32 width, Int32 height)
		{
			mNativeWindow->SetSize(width, height);
		}

		void SetWidth(Int32 width)
		{
			mNativeWindow->SetWidth(width);
		}

		void SetHeight(Int32 height)
		{
			mNativeWindow->SetHeight(height);
		}

		const std::string& GetTitle() const
		{
			return mNativeWindow->GetTitle();
		}

		Int32 GetPositionX()
		{
			return mNativeWindow->GetPositionX();
		}

		Int32 GetPositionY()
		{
			return mNativeWindow->GetPositionY();
		}

		Int32 GetWidth()
		{
			return mNativeWindow->GetWidth();
		}

		Int32 GetHeight()
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

		Builder& SetPosition(Int32 x, Int32 y)
		{
			mPosX = x;
			mPosY = y;
			return *this;
		}

		Builder& SetSize(Int32 w, Int32 h)
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
		Int32 mWidth, mHeight;
		Int32 mPosX, mPosY;
		std::string mTitle;
	};

} }

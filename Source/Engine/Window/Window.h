#pragma once

#include <string>
#include "Native/INativeWindow.h"

namespace Hx { namespace Window {

    class Window
    {
    public:
        class Builder;

    public:
        Window(int width = 640, int height = 480,
            const std::string& title = "Hexagon Engine", int posX = -1, int posY = -1);
        
        ~Window();

        void SetTitle(const std::string& str)
        {
            this->NativeWindow->SetTitle(str);
        }

        void SetTitle(const char* title)
        {
            this->NativeWindow->SetTitle(std::string(title));
        }

        void SetPosition(int x, int y)
        {
            this->NativeWindow->SetPosition(x, y);
        }

        void SetSize(int width, int height)
        {
            this->NativeWindow->SetSize(width, height);
        }

        void SetWidth(int width)
        {
            this->NativeWindow->SetWidth(width);
        }

        void SetHeight(int height)
        {
            this->NativeWindow->SetHeight(height);
        }

        const std::string& GetTitle() const
        {
            return this->NativeWindow->GetTitle();
        }

        int GetPositionX()
        {
            return this->NativeWindow->GetPositionX();
        }

        int GetPositionY()
        {
            return this->NativeWindow->GetPositionY();
        }

        int GetWidth()
        {
            return this->NativeWindow->GetWidth();
        }

        int GetHeight()
        {
            return this->NativeWindow->GetHeight();
        }

    private:
        Native::INativeWindow* NativeWindow;
    };

    class Window::Builder
    {
    public:
        Builder() :
            Width(640),
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

        Builder& SetPosition(int x, int y)
        {
            this->PosX = x;
            this->PosY = y;
            return *this;
        }

        Builder& SetSize(int width, int height)
        {
            this->Width = width;
            this->Height = height;
            return *this;
        }

        Window Build()
        {
            return Window(Width, Height, Title, PosX, PosY);
        }

    private:
        int Width, Height;
        int PosX, PosY;
        std::string Title;
    };

} }

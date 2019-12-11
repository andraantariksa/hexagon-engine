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
        Window(Int32 width = 640, Int32 height = 480,
            const std::string& title = "Hexagon Engine", Int32 posX = -1, Int32 posY = -1);
        
        ~Window();

        void SetTitle(const std::string& str)
        {
            this->NativeWindow->SetTitle(str);
        }

        void SetTitle(const char* title)
        {
            this->NativeWindow->SetTitle(std::string(title));
        }

        void SetPosition(Int32 x, Int32 y)
        {
            this->NativeWindow->SetPosition(x, y);
        }

        void SetSize(Int32 width, Int32 height)
        {
            this->NativeWindow->SetSize(width, height);
        }

        void SetWidth(Int32 width)
        {
            this->NativeWindow->SetWidth(width);
        }

        void SetHeight(Int32 height)
        {
            this->NativeWindow->SetHeight(height);
        }

        const std::string& GetTitle() const
        {
            return this->NativeWindow->GetTitle();
        }

        Int32 GetPositionX()
        {
            return this->NativeWindow->GetPositionX();
        }

        Int32 GetPositionY()
        {
            return this->NativeWindow->GetPositionY();
        }

        Int32 GetWidth()
        {
            return this->NativeWindow->GetWidth();
        }

        Int32 GetHeight()
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

        Builder& SetPosition(Int32 x, Int32 y)
        {
            this->PosX = x;
            this->PosY = y;
            return *this;
        }

        Builder& SetSize(Int32 w, Int32 h)
        {
            this->Width = w;
            this->Height = h;
            return *this;
        }

        Window Build()
        {
            return Window(Width, Height, Title, PosX, PosY);
        }

    private:
        Int32 Width, Height;
        Int32 PosX, PosY;
        std::string Title;
    };

} }

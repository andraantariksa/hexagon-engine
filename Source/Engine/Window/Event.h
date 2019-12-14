#pragma once

#include "../Types.h"

namespace Hx { namespace Window {

	enum EventType
	{
		// Keyboard events
		KeyDown,
		KeyUp,

		// Mouse events
		MouseBtnDown,
		MouseBtnUp,
		MouseWheel,
		MouseMove,
		MouseHover,
		MouseLeave,

		// Window events
		WindowClose,
		WindowResize,
		WindowMove,
		WindowLostFocus,
		WindowGainFocus,
	};

	class Event
	{
	public:
		Event();
		~Event();
		void Process();

		struct SizeEvent
		{
			int32 Width;
			int32 Height;
		};

		struct KeyEvent
		{
			int8 KeyCode;
			bool ControlKey;
			bool ShiftKey;
			bool AltKey;
			bool Toggle;
		};
	private:
        // SDL_Event *EventInstance;
	};

} }

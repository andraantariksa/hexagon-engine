#pragma once

#include "../Types.h"

namespace Hx { namespace Window {

	enum EEventType
	{
		// Keyboard events
		EventType_KeyDown,
		EventType_KeyUp,

		// Mouse events
		EventType_MouseBtnDown,
		EventType_MouseBtnUp,
		EventType_MouseWheel,
		EventType_MouseMove,
		EventType_MouseHover,
		EventType_MouseLeave,

		// Window events
		EventType_WindowClose,
		EventType_WindowResize,
		EventType_WindowMove,
		EventType_WindowLostFocus,
		EventType_WindowGainFocus,
	};

	class Event
	{
	public:

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

	};

} }

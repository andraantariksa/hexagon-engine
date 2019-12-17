#pragma once

#include "../Types.h"
#include "Keyboard.h"

namespace Hx { namespace Window {

	enum class EventType : uint8
	{
		// Keyboard events
		KeyDown,
		KeyUp,

		// Mouse events
		MouseBtnDown,
		MouseBtnUp,
		MouseWheel,
		MouseMove,

		// Window events
		WindowClose,
		WindowResize,
		WindowMove,
		WindowLostFocus,
		WindowGainFocus,

		Count
	};

	enum class MouseButton : uint8
	{
		Left = 1,
		Middle,
		Right,
		X1,
		X2,

		Count
	};

	struct SizeEventData
	{
		int32 Width;
		int32 Height;
	};

	struct MouseEventData
	{
		MouseButton Button;
		uint8 Clicks;
		int32 X;
		int32 Y;
	};

	struct MouseMotionEventData
	{
		uint8 Buttons;
		int32 X;
		int32 Y;
		int32 RelativeX;
		int32 RelativeY;
	};

	struct MouseWheelEventData
	{
		int32 AmountX;
		int32 AmountY;
		bool Direction;
	};

	struct KeyEventData
	{
		Keycode KeyCode;
		bool LControlKey;
		bool LShiftKey;
		bool LAltKey;
		bool RControlKey;
		bool RShiftKey;
		bool RAltKey;
		bool ControlKey;
		bool ShiftKey;
		bool AltKey;
		bool NumLockKey;
		bool CapsLockKey;
		bool Repeat;
	};

	struct Event
	{
		EventType Type;

		union
		{
			MouseEventData MouseButtonEvent;
			MouseMotionEventData MouseMoveEvent;
			MouseWheelEventData MouseWheelEvent;
			KeyEventData KeyboardEvent;
			SizeEventData WindowResize;
		};
	};

} }

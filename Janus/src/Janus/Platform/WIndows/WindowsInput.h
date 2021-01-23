#pragma once

#include "Janus/Input.h"

namespace Janus {
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;

	};
}

#ifdef JN_PLATFORM_WINDOWS
#define CREATE_WINDOWS_INPUT_INSTANCE //Input* Input::s_Instance = new WindowsInput();
#define CREATE_WINDOWS_INPUT_INSTANCE 
#endif
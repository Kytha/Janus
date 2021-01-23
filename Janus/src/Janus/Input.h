#pragma once
#include "Janus/Core.h"
namespace Janus {
	// The Input class is a signleton and should only have once instance
	// Used for input polling
	class JANUS_API Input
	{
	public:
		// API for access platform specific implementation
		inline static bool IsKeyPressed(int keycode) {
			return s_Instance->IsKeyPressedImpl(keycode);
		}
		inline static bool IsMouseButtonPressed(int button) {
			return s_Instance->IsMouseButtonPressedImpl(button);
		}
		inline static std::pair<float, float> GetMousePosition() {
			return s_Instance->GetMousePositionImpl();
		}
		inline static float GetMouseY() {
			return s_Instance->GetMouseYImpl();
		}
		inline static float GetMouseX() {
			return s_Instance->GetMouseXImpl();
		}
	protected:
		// Interface for platform specific input handling
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_Instance;
	};
}

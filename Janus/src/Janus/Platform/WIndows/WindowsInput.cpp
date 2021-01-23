#include "jnpch.h"
#include "WindowsInput.h"
#include <GLFW/glfw3.h>
#include "Janus/Application.h"



namespace Janus {

	// TEMP
	// Static decleration of input instance for Windows platform. 
	Input* Input::s_Instance = new WindowsInput();
	CREATE_WINDOWS_INPUT_INSTANCE

	// Input polling windows implementations
	// Interfaces with glfw

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	 }

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair <float, float> WindowsInput::GetMousePositionImpl() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float WindowsInput::GetMouseXImpl() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

}

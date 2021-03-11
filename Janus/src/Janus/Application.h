#pragma once
#include "Janus/Core.h"
#include "Janus/Core/Timestep.h"
#include "Window.h"
#include "Events/Event.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"
#include "Janus/Events/ApplicationEvent.h"

namespace Janus {

	// Application is a signleton object which maintains the window and game loop
	class JANUS_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);

		void PushOverlay(Layer* layer);

		// Exposes the window object for input polling
		inline Window& GetWindow() { return  *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		// Pointer to the applications window object. An application can only have one window
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		// Pointer to the apps application object
		static Application* s_Instance;
	};

	// To be defined in client
	// Client defines a Janus Application object to be returned by this function
	Application* CreateApplication();
}


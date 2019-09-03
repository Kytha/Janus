#pragma once
#include "Janus/Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "LayerStack.h"
#include "Janus/Events/ApplicationEvent.h"

namespace Janus {
	class JANUS_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}


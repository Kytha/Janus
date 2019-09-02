#include "Janus/Application.h"

#include "Janus/Events/ApplicationEvent.h"
#include "Janus/Log.h"

namespace Janus {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			JN_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			JN_TRACE(e);
		}

		while (true) {

		}
	}
}
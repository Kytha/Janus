#pragma once
#include "Core.h"

namespace Janus {
	class JANUS_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}


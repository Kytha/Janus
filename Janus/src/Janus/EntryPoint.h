#pragma once

#ifdef JN_PLATFORM_WINDOWS

extern Janus::Application* Janus::CreateApplication();

// ENTRY POINT
int main(int argc, char** argv)
{
	//Initialize both client and core loggers
	Janus::Log::Init();
	JN_CORE_WARN("Intialized Log");

	// Get client defined application object and start app loop
	auto app = Janus::CreateApplication();
	app->Run();
	delete app;
}

#endif
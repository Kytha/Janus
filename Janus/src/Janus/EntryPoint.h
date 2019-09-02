#pragma once

#ifdef JN_PLATFORM_WINDOWS

extern Janus::Application* Janus::CreateApplication();

int main(int argc, char** argv)
{
	Janus::Log::Init();
	JN_CORE_WARN("Intialized Log");
	int a = 5;
	JN_INFO("Hello! Var={0}", a);
	auto app = Janus::CreateApplication();
	app->Run();
	delete app;
}

#endif
#include <Janus.h>

class Sandbox : public Janus::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Janus::Application* Janus::CreateApplication()
{
	return new Sandbox();
}
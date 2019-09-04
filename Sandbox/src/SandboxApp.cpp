#include <Janus/Janus.h>

class ExampleLayer : public Janus::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
	}

	void OnEvent(Janus::Event& event) override
	{
		if (event.GetEventType() == Janus::EventType::KeyPressed)
		{
			Janus::KeyPressedEvent& e = (Janus::KeyPressedEvent&)event;
			JN_TRACE("{}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Janus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Janus::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Janus::Application* Janus::CreateApplication()
{
	return new Sandbox();
}
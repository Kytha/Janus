#include <Janus/Janus.h>
#include "imgui/imgui.h"

class ExampleLayer : public Janus::Layer
{
public:
	ExampleLayer()
		:Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f), m_CameraRotation(0.0f)
	{
		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		};

		uint32_t indices[3] = { 0, 1, 2 };
		m_VertexArray.reset(Janus::VertexArray::Create());

		std::shared_ptr<Janus::VertexBuffer> triangleVB;
		triangleVB.reset(Janus::VertexBuffer::Create(vertices, sizeof(vertices)));

		Janus::BufferLayout layout = {
			{ Janus::ShaderDataType::Float3, "a_Position" },
			{ Janus::ShaderDataType::Float4, "a_Color" }
		};

		triangleVB->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(triangleVB);

		std::shared_ptr<Janus::IndexBuffer> triangleIB;
		triangleIB.reset(Janus::IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(triangleIB);


		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5, 0.0f,
			0.5f, 0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f,
		};

		uint32_t squareIndices[6] = { 0,1,2,2,3,0 };


		// Vertex Array
		// Vertex Buffer
		// Index Buffer


		m_SquareVA.reset(Janus::VertexArray::Create());

		std::shared_ptr<Janus::VertexBuffer> squareVB;
		squareVB.reset(Janus::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ Janus::ShaderDataType::Float3, "a_Position" },
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		std::shared_ptr<Janus::IndexBuffer> squareIB;
		squareIB.reset(Janus::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

		m_SquareVA->SetIndexBuffer(squareIB);
		//m_IndexBuffer->Bind();

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
				v_Position = a_Position;
				v_Color = a_Color;
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec4 v_Color;
			void main()
			{
				color = v_Color;
			}
		)";
		m_Shader.reset(new Janus::Shader(vertexSrc, fragmentSrc));
		// Shader - vertex shader, fragment shader

		std::string vertexSrc2 = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			out vec3 v_Position;

			void main()
			{
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
				v_Position = a_Position;
			}
		)";

		std::string fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";
		m_Shader2.reset(new Janus::Shader(vertexSrc2, fragmentSrc2));
	}

	void OnUpdate(Janus::Timestep ts) override
	{

		JN_TRACE("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
		if (Janus::Input::IsKeyPressed(JN_KEY_A))
		{
			m_CameraPosition.x -= m_CameraSpeed * ts;
		}
		else if (Janus::Input::IsKeyPressed(JN_KEY_D))
		{
			m_CameraPosition.x += m_CameraSpeed * ts;
		}
		if (Janus::Input::IsKeyPressed(JN_KEY_W))
		{
			m_CameraPosition.y += m_CameraSpeed * ts;
		}
		else if (Janus::Input::IsKeyPressed(JN_KEY_S))
		{
			m_CameraPosition.y -= m_CameraSpeed * ts;
		}

		if (Janus::Input::IsKeyPressed(JN_KEY_Q))
		{
			m_CameraRotation += 15.0f * ts;
		}

		if (Janus::Input::IsKeyPressed(JN_KEY_E))
		{
			m_CameraRotation -= 15.0f * ts;
		}

		Janus::RenderCommand::SetClearColor({ 0.34f, 0.52f, 0.77f, 1 });
		Janus::RenderCommand::Clear();
		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);
		Janus::Renderer::BeginScene(m_Camera);

		Janus::Renderer::Submit(m_Shader2, m_SquareVA);
		Janus::Renderer::Submit(m_Shader, m_VertexArray);

		Janus::Renderer::EndScene();
	}

	void OnEvent(Janus::Event& event) override
	{

	}

	virtual void OnImGuiRender() override
	{


	}
private:
	std::shared_ptr<Janus::Shader> m_Shader;
	std::shared_ptr<Janus::Shader> m_Shader2;

	std::shared_ptr<Janus::VertexArray> m_VertexArray;

	std::shared_ptr<Janus::VertexArray> m_SquareVA;

	Janus::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraRotation;
	float m_CameraSpeed = 5.0f;
};


class Sandbox : public Janus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Janus::Application* Janus::CreateApplication()
{
	return new Sandbox();
}
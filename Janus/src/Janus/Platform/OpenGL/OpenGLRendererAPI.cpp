#include "jnpch.h";
#include "OpenGLRendererAPI.h";
#include <glad/glad.h>;

namespace Janus {

	OpenGLRendererAPI::OpenGLRendererAPI()
	{
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
	}

}
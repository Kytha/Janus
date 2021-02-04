#pragma once
#include "Janus/Renderer/RendererAPI.h";

namespace Janus {
	class OpenGLRendererAPI : public RendererAPI {
	public:
		OpenGLRendererAPI();

		virtual void Clear() override;
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;

	};
}
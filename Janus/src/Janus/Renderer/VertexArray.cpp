#include "jnpch.h";
#include "Buffer.h";
#include "Renderer.h";
#include "Janus/Platform/OpenGL/OpenGLVertexArray.h";
#include "VertexArray.h";

namespace Janus {
	VertexArray* VertexArray::Create() {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None:
			JN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		}
		JN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
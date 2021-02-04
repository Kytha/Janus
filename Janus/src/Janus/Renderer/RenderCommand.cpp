#include "jnpch.h";
#include "RenderCommand.h";
#include "Janus/Platform/OpenGL/OpenGLRendererAPI.h";

namespace Janus {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}
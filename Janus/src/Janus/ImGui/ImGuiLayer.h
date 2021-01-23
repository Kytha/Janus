#pragma once
#include "Janus/Layer.h"

#include "Janus/Events/KeyEvent.h"
#include "Janus/Events/MouseEvent.h"
#include "Janus/Events/ApplicationEvent.h"
namespace Janus {

	class JANUS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnImGuiRender() override;
		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
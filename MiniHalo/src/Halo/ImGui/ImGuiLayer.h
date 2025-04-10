#pragma once

#include "Halo/Layer.h"
#include "Halo/Application.h"

namespace MiniHalo
{
	class HALO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		float m_Time = 0.0f;
	};
}
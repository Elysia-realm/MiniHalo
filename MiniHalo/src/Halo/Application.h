#pragma once

#include "Window.h"
#include "Core.h"
#include "Halo/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace MiniHalo
{
	class HALO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& GetSingleInstance() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;

		// single instance
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
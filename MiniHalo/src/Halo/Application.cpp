#include "Application.h"

#include "Halo/Events/ApplicationEvent.h"
#include "Halo/Log.h"

namespace MiniHalo
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		HA_INFO(e.ToString());

		while (true);
	}
}
#pragma once

#include "Core.h"

namespace MiniHalo
{
	class HALO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
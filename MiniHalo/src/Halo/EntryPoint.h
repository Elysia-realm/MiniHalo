#pragma once

#ifdef HALO_PLATFORM_WINDOWS

extern MiniHalo::Application* MiniHalo::CreateApplication();
	
int main(int argc, char** argv)
{
	MiniHalo::Log::Init();
	HA_CORE_WARN("Engine Log Initialized...");
	HA_INFO("Oath! Welcome to MiniHalo.");

	auto app = MiniHalo::CreateApplication();
	app->Run();
	delete app;
}

#endif  
#pragma once

#ifdef HALO_PLATFORM_WINDOWS

extern MiniHalo::Application* MiniHalo::CreateApplication();
	
int main(int argc, char** argv)
{
	printf("MiniHalo Start\n");
	auto app = MiniHalo::CreateApplication();
	app->Run();
	delete app;
}

#endif  
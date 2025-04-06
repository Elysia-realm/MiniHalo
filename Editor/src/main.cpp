#include <Halo.h>

class Editor : public MiniHalo::Application
{
public:
	Editor()
	{

	}

	~Editor()
	{

	}
};

MiniHalo::Application* MiniHalo::CreateApplication()
{
	return new Editor();
}
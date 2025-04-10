#include <Halo.h>

class ExampleLayer : public MiniHalo::Layer
{
public:
	ExampleLayer()
		: Layer("Example Layer") {}

	void OnUpdate() override
	{
		HA_INFO("ExampleLayer::Update");
	}

	void OnEvent(MiniHalo::Event& e) override
	{
		HA_INFO("{0}", e.ToString());
	}
};

class Editor : public MiniHalo::Application
{
public:
	Editor()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new MiniHalo::ImGuiLayer());
	}

	~Editor()
	{

	}
};

MiniHalo::Application* MiniHalo::CreateApplication()
{
	return new Editor();
}
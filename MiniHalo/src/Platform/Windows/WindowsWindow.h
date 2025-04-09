#pragma once

#include "Halo/Window.h"

#include <GLFW/glfw3.h>

namespace MiniHalo
{
	class HALO_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);

		void OnUpdate() override;

		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline unsigned int GetWidth() const override { return m_Data.Width; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EvenCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual ~WindowsWindow();
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Height;
			unsigned int Width;

			bool VSync;

			EventCallbackFn EvenCallback;
		};

		WindowData m_Data;
	};
}
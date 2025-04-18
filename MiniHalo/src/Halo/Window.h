#pragma once

#include "hapch.h"

#include "Halo/Core.h"
#include "Halo/Events/Event.h"

namespace MiniHalo
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Height;
		unsigned int Width;

		WindowProps(const std::string& title = "MiniHalo", unsigned int w = 1920, unsigned int h = 1080)
			: Title(title), Height(h), Width(w) {}
	};

	// Interface representing a desktop system based Window
	class HALO_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetHeight() const = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual void* GetNativeWindow() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

		virtual ~Window() {}
	};
}
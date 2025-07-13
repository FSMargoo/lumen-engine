/**
 * Window.h:
 *      @Descripiton    :   The window class for Lumen Engine
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"

#include <Events/Event.h>
#include <Core.h>

namespace Lumen {
/**
 * The property for the window
 */
struct WindowProperties {
	std::string Title  = "Lumen Engine";
	int         Width  = 1280;
	int         Height = 720;
};

/**
 * The abstracted Window class
 */
class Window {
public:
	using EventCallBack = std::function<void(Event &)>;

public:
	virtual ~Window() = default;

	virtual void OnUpdate() = 0;

	[[nodiscard]] virtual int GetWidth() const = 0;
	[[nodiscard]] virtual int GetHeight() const = 0;

	virtual void SetEventCallback(const EventCallBack &Callback) = 0;
	virtual void SetVSync(bool Enabled) = 0;
	[[nodiscard]] virtual bool IsVSync() const = 0;

public:
	virtual void *GetNativeWindow() const = 0;

public:
	static Window *Create(const WindowProperties &Properties);
};

}

#endif //WINDOW_H
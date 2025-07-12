/**
 * WindowsWindow.h:
 *      @Descripiton    :   The window implementation for Windows plat
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include <GLFW/glfw3.h>

#include <Events/ApplicationEvent.h>
#include <Events/MouseEvent.h>
#include <Events/KeyEvent.h>

#include <Window.h>

namespace Lumen {

class WindowsWindow : public Window {
public:
	WindowsWindow(const WindowProperties &Property);

	~WindowsWindow();

public:
	void OnUpdate() override;

	int GetWidth() const override;

	int GetHeight() const override;

	void SetEventCallback(const EventCallBack &Callback) override;

	void SetVSync(bool Enabled) override;

	bool IsVSync() const override;

private:
	void Init(const WindowProperties &Property);

	void Shutdown();

private:
	struct WindowsWindowData {
		std::string   Title;
		unsigned int  Width;
		unsigned int  Height;
		bool          VSync;
		EventCallBack EventCallBack;
	};

	WindowsWindowData _data;

private:
	GLFWwindow *_window;
};
}

#endif //WINDOWSWINDOW_H

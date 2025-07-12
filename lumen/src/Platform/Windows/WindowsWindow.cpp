/**
 * WindowsWindow.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#include <Platform/Windows/WindowsWindow.h>

namespace Lumen {
static void GLFWErrorCallback(int Error, const char* Description) {
	Log::Fatal("GLFW Error [{}]: {}", Error, Description);
}

Window *Window::Create(const WindowProperties &Property) {
	return new WindowsWindow(Property);
}

WindowsWindow::WindowsWindow(const WindowProperties &Property) {
	Init(Property);
}

WindowsWindow::~WindowsWindow() {
	Shutdown();
}

void WindowsWindow::Init(const WindowProperties &Property) {
	static bool GLFWInit = false;

	_data.Title  = Property.Title;
	_data.Width  = Property.Width;
	_data.Height = Property.Height;

	Log::CoreInfo("Creating window \"{0}\" [{1} x {2}]", Property.Title, Property.Width, Property.Height);

	if (!GLFWInit) {
		GLFWInit = true;

		int success = glfwInit();
		LUMEN_CORE_ASSERT(success, "Could not initialize GLFW!");

		glfwSetErrorCallback(GLFWErrorCallback);

		GLFWInit = true;
	}

	_window = glfwCreateWindow(_data.Width, _data.Height, _data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(_window);
	glfwSetWindowUserPointer(_window, &_data);

	SetVSync(true);

	glfwSetWindowSizeCallback(_window, [](GLFWwindow *Window, int Width, int Height) {
		WindowResizeEvent event(Width, Height);
		auto              data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		data->EventCallBack(event);

		data->Width  = Width;
		data->Height = Height;
	});
	glfwSetWindowCloseCallback(_window, [](GLFWwindow *Window) {
		WindowCloseEvent event;
		auto             data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		data->EventCallBack(event);
	});
	glfwSetWindowFocusCallback(_window, [](GLFWwindow *Window, int Focus) {
		auto data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		if (Focus == GLFW_TRUE) {
			WindowFocusEvent event;
			data->EventCallBack(event);
		} else {
			WindowLostFocusEvent event;
			data->EventCallBack(event);
		}
	});
	glfwSetKeyCallback(_window, [](GLFWwindow *Window, int Key, int Scancode, int Action, int Mods) {
		auto data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		switch (Action) {
		case GLFW_RELEASE: {
			KeyPressedEvent event(Key, 0);
			data->EventCallBack(event);

			break;
		}
		case GLFW_PRESS: {
			KeyReleasedEvent event(Key);
			data->EventCallBack(event);

			break;
		}
		case GLFW_REPEAT: {
			KeyPressedEvent event(Key, 1);
			data->EventCallBack(event);

			break;
		}
		default: {
			break;
		}
		}
	});

	glfwSetMouseButtonCallback(_window, [](GLFWwindow *Window, int Button, int Action, int Mods) {
		auto data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		switch (Action) {
		case GLFW_PRESS: {
			MouseButtonPressedEvent event(Button);
			data->EventCallBack(event);

			break;
		}
		case GLFW_RELEASE: {
			MouseButtonReleasedEvent event(Button);
			data->EventCallBack(event);

			break;
		}
		}
	});

	glfwSetScrollCallback(_window, [](GLFWwindow *Window, double ScrollOffsetX, double ScrollOffsetY) {
		auto data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		MouseScrollEvent event(ScrollOffsetX, ScrollOffsetY);
		data->EventCallBack(event);
	});

	glfwSetCursorPosCallback(_window, [](GLFWwindow *Window, double PosX, double PosY) {
		auto data = static_cast<WindowsWindowData *>(glfwGetWindowUserPointer(Window));

		MouseMovedEvent event(PosX, PosY);
		data->EventCallBack(event);
	});
}

void WindowsWindow::Shutdown() {
	glfwDestroyWindow(_window);
}

void WindowsWindow::OnUpdate() {
	glfwPollEvents();
	glfwSwapBuffers(_window);
}

void WindowsWindow::SetVSync(bool Enabled) {
	glfwSwapInterval(Enabled);

	_data.VSync = Enabled;
}

int WindowsWindow::GetWidth() const {
	return _data.Width;
}

int WindowsWindow::GetHeight() const {
	return _data.Height;
}

void WindowsWindow::SetEventCallback(const EventCallBack &Callback) {
	_data.EventCallBack = Callback;
}

bool WindowsWindow::IsVSync() const {
	return _data.VSync;
}

}

/**
 * WindowsInput.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/13/2025
 */

#include <Platform/Windows/WindowsInput.h>

namespace Lumen {
Input *Input::_instance = new WindowsInput();

bool WindowsInput::IsKeyPressedImpl(int Key) {
	auto window = static_cast<GLFWwindow *>(Application::App->GetWindow()->GetNativeWindow());
	auto status = glfwGetKey(window, Key);

	return status == GLFW_PRESS || status == GLFW_REPEAT;
}

bool WindowsInput::IsMousePressedImpl(int Button) {
	auto window = static_cast<GLFWwindow *>(Application::App->GetWindow()->GetNativeWindow());
	auto status = glfwGetMouseButton(window, Button);

	return status == GLFW_PRESS;
}

int WindowsInput::GetMouseXImpl() {
	auto window = static_cast<GLFWwindow *>(Application::App->GetWindow()->GetNativeWindow());

	double x;
	double y;

	glfwGetCursorPos(window, &x, &y);

	return static_cast<int>(x);
}

int WindowsInput::GetMouseYImpl() {
	auto window = static_cast<GLFWwindow *>(Application::App->GetWindow()->GetNativeWindow());

	double x;
	double y;

	glfwGetCursorPos(window, &x, &y);

	return static_cast<int>(y);
}

std::tuple<int, int> WindowsInput::GetMousePositionImpl() {
	auto window = static_cast<GLFWwindow *>(Application::App->GetWindow()->GetNativeWindow());

	double x;
	double y;

	glfwGetCursorPos(window, &x, &y);

	return { static_cast<int>(x), static_cast<int>(y) };
}
}

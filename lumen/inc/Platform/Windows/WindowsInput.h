/**
 * WindowsInput.h:
 *      @Descripiton    :   The Input class implementation on Windows platform
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/13/2025
 */

#ifndef WINDOWSINPUT_H
#define WINDOWSINPUT_H

#include <Application.h>
#include <Input.h>

namespace Lumen {
class WindowsInput : public Input {
protected:
	bool IsKeyPressedImpl(int Key) override;

	bool IsMousePressedImpl(int Button) override;

	int GetMouseXImpl() override;

	int GetMouseYImpl() override;

	std::tuple<int, int> GetMousePositionImpl() override;
};
}

#endif //WINDOWSINPUT_H

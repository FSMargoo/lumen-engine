/**
 * Input.h:
 *      @Descripiton    :   The input abstracted interface
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/13/2025
 */

#ifndef INPUT_H
#define INPUT_H

namespace Lumen {

class Input {
public:
	Input() = default;

	virtual ~Input() = default;

public:
	static bool IsKeyPressed(int Key) {
		return _instance->IsKeyPressedImpl(Key);
	}

	static int IsMouseButtonPressed(int Button) {
		return _instance->IsMousePressedImpl(Button);
	}

	static int GetMouseX() {
		return _instance->GetMouseXImpl();
	}

	static int GetMouseY() {
		return _instance->GetMouseYImpl();
	}

	static std::tuple<int, int> GetMousePosition() {
		return _instance->GetMousePositionImpl();
	}

protected:
	virtual bool IsKeyPressedImpl(int Key) = 0;

	virtual bool IsMousePressedImpl(int Button) = 0;

	virtual int GetMouseXImpl() = 0;

	virtual int GetMouseYImpl() = 0;

	virtual std::tuple<int, int> GetMousePositionImpl() = 0;

private:
	static Input *_instance;
};
}

#endif //INPUT_H

/**
 * Layer.h:
 *      @Descripiton    :   The layer definition of the Lumen Engine
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/12/2025
 */
#ifndef LAYER_H
#define LAYER_H

#include <Events/Event.h>

#include <Core.h>

namespace Lumen {
class Layer {
public:
	Layer(const std::string &Name = "Layer");

	virtual ~Layer() = default;

public:
	virtual void OnAttach() {
	}

	virtual void OnDetach() {
	}

	virtual void OnUpdate() {
	}

	virtual void OnEvent(Event &E) {
	}

public:
	[[nodiscard]] const std::string &GetName() const {
		return _debugName;
	}

protected:
	std::string _debugName;
};
}

#endif //LAYER_H

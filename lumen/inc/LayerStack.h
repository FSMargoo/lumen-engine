/**
 * LayerStack.h:
 *      @Descripiton    :   DESHERE
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/12/2025
 */
#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include <Layer.h>

#include <vector>

namespace Lumen {
/**
 * Once you pushed a layer into the layer stack, the layer stack
 * will handle the lifetime of the layer
 */
class LayerStack {
public:
	LayerStack();

	~LayerStack();

public:
	void PushLayer(Layer *Layer);

	void PushOverlay(Layer *Overlay);

	void PopLayer(Layer *Layer);

	void PopOverlay(Layer *Overlay);

public:
	auto begin() {
		return _layers.begin();
	}

	auto end() {
		return _layers.end();
	}

private:
	std::vector<Layer *>           _layers;
	std::vector<Layer *>::iterator _layerIterator;
};
}

#endif //LAYERSTACK_H

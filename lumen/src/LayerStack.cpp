/**
 * LayerStack.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/12/2025
 */

#include <LayerStack.h>

namespace Lumen {
LayerStack::LayerStack() {
	_layerIterator = _layers.begin();
}

LayerStack::~LayerStack() {
	for (auto &layer : _layers) {
		delete layer;
	}
}

void LayerStack::PushLayer(Layer *Layer) {
	_layerIterator = _layers.emplace(_layerIterator, Layer);
}

void LayerStack::PushOverlay(Layer *Overlay) {
	_layers.emplace_back(Overlay);
}

void LayerStack::PopLayer(Layer *Layer) {
	auto iterator = std::find(_layerIterator, _layers.end(), Layer);
	if (iterator != _layers.end()) {
		_layers.erase(iterator);
		--_layerIterator;
	}
}

void LayerStack::PopOverlay(Layer *Overlay) {
	auto iterator = std::find(_layers.begin(), _layers.end(), Overlay);
	if (iterator != _layers.end()) {
		_layers.erase(iterator);
	}
}
}

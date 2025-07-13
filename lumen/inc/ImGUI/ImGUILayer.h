/**
 * ImGUILayer.h:
 *      @Descripiton    :   The layer for ImGUI
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/12/2025
 */

#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include <Layer.h>

#include <Platform/Windows/WindowsWindow.h>

#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

namespace Lumen {
class ImGUILayer : public Layer {
public:
	ImGUILayer();
	~ImGUILayer() override = default;

public:
	void OnAttach() override;
	void OnUpdate() override;

private:
	float _time;
};
}

#endif //IMGUILAYER_H

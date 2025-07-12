/**
 * Application.h:
 *      @Descripiton    :   The application class for the Lumen Engine
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */
#ifndef APPLICATION_H
#define APPLICATION_H

#include <Events/Event.h>
#include <Events/ApplicationEvent.h>

#include <LayerStack.h>

#include <memory>

namespace Lumen {
/**
 * The application class for Lumen Engine
 */
class Application {
public:
	Application() = default;

	virtual ~Application() = default;

public:
	/**
	 * Running the application
	 * @return The status code of the application
	 */
	virtual int Run() = 0;

public:
	void PushLayer(Layer *Layer);

	void PushOverlay(Layer *Overlay);

public:
	bool OnWindowClose(WindowCloseEvent &E);

public:
	virtual void OnEvent(Event &E);
	virtual void OnUpdate();

protected:
	bool _running = true;

	LayerStack _layerStack;
};

/**
 * Client should declare this function
 * @return The application that created
 */
Lumen::Application *CreateApplication();
}

#endif //APPLICATION_H

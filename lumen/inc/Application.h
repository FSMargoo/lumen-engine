/**
 * Application.h:
 *      @Descripiton    :   The application class for the Lumen Engine
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */
#ifndef APPLICATION_H
#define APPLICATION_H

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
};

/**
 * This function should be declared by client
 * @return The application that created
 */
Lumen::Application* CreateApplication();
}

#endif //APPLICATION_H

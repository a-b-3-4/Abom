#include <Abom.h>

class Sandbox : public Abom::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
	void Run() {
		AB_TRACE("Sandbox started!");

		AB_TRACE("hey, i am a trace!");
		AB_INFO("hey, i am an info!");
		AB_WARN("hey, i am a warning!");
		AB_ERROR("hey, i am a error!");
	}
};

Abom::Application* Abom::CreateApplication() {
	return new Sandbox();
}
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
};

Abom::Application* Abom::CreateApplication() {
	return new Sandbox();
}
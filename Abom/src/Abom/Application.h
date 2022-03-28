#pragma once

#include "Core.h"

namespace Abom
{
	class ABOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	//To be implemented by CLIENT

	Application* CreateApplication();
}
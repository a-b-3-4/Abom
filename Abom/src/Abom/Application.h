#pragma once

#include "Core.h"

namespace Abom
{
	class ABOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in a CLIENT

	Application* CreateApplication();
}
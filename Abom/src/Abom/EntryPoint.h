#pragma once

#ifdef AB_PLATFORM_WINDOWS

extern Abom::Application* Abom::CreateApplication();

int main(int arcgc, char** argv)
{
	Abom::Log::Initialize();
	AB_CORE_WARN("Initialized Log!");
	auto app = Abom::CreateApplication();
	app->Run();
	delete app;
}

#endif
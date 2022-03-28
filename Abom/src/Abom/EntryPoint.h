#pragma once

#ifdef AB_PLATFORM_WINDOWS

extern Abom::Application* Abom::CreateApplication();

int main(int arcgc, char** argv)
{
	Abom::Log::Initialize();
	auto app = Abom::CreateApplication();
	app->Run();
	delete app;
	Abom::Log::Finalize();
}

#endif
#pragma once

#ifdef E3_PLATFORM_WINDOWS

extern Vega::Application* Vega::CreateApplication();

int main(int argc, char** argv)
{
	Vega::Log::Init();
	VG_CORE_WARN("Initialized Log!");
	VG_INFO("Hello!");

	auto app = Vega::CreateApplication();
	app->Run();
	delete app;
}

#endif
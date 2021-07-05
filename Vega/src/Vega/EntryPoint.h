#pragma once

#ifdef E3_PLATFORM_WINDOWS

extern Vega::Application* Vega::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Vega::CreateApplication();
	app->Run();
	delete app;
}

#endif
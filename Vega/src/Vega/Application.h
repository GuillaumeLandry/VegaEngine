#pragma once

#include "Core.h"

namespace Vega {

	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


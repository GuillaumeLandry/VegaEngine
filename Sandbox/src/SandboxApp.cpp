#include "Vega.h"

class Sandbox : public Vega::Application {
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Vega::Application* Vega::CreateApplication()
{
	return new Sandbox();
}
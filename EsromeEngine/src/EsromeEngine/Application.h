#pragma once

#include "Core.h"

namespace EsromeEngine {
	class ESROME_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();
	};

	//This is to be defined by the client, not the engine.
	Application* CreateApplication();
}


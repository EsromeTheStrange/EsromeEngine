#pragma once
#include "Application.h"//Temp Fix, remove later

#ifdef EE_PLATFORM_WINDOWS

extern EsromeEngine::Application* EsromeEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = EsromeEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
#pragma once
#include "Log.h"//This is
#include "Application.h"//Temporary, remove it later.

#ifdef EE_PLATFORM_WINDOWS

extern EsromeEngine::Application* EsromeEngine::CreateApplication();

int main(int argc, char** argv) {
	EsromeEngine::Log::Init();
	EE_CORE_WARN("Esrome Engine Started!");
	EE_INFO("Something Something");

	auto app = EsromeEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
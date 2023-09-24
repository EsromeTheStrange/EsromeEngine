#include <EsromeEngine.h>

class Sandbox : public EsromeEngine::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

EsromeEngine::Application* EsromeEngine::CreateApplication() {
	return new Sandbox();
}
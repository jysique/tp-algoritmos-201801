#include "FormFlappyBird.h"

using namespace TFAlgoritmos;

int main() {
	FormFlappyBird^ flappybirds = gcnew FormFlappyBird;
	Application::Run(flappybirds);
	Application::EnableVisualStyles();
}
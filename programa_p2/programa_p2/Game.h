#pragma once
#include "Scene.h"
#include "MainMenu.h"
#include <chrono>

using namespace std::chrono; //Para que reconozca miliseconds

class Game
{
private:
	const double TIME_INCREMENT = 0.4; //ms tiempo en el juego
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	Scene* currentScene; //La escena en la que se encuentra el juego ahora mismo
	vector<Scene*> sceneCollection;

public:
	Game() : currentScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0){ }

	void Init();
	void Render();
	void Update(const float& time);

	void CheckForSceneChange(); //Conprueba periódicamente si currentScene manda una señal para cambiar de escena

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};


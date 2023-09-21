#pragma once
#include "Scene.h"
class MainMenu : public Scene
{
private:
	Text menuTitle;
	Text description;
	Text instruction;
	Text start;

	bool ready = false;//Si está listo para comenzar el juego

public:
	MainMenu() { /*camera = (Vector3D(0, 0, 0));**/ };

	void Init();
	void Render();
	void ProcessKeyPressed(unsigned char key, int px, int py);

	int ChangeScene();
};


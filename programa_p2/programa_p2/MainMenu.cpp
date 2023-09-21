#include "MainMenu.h"
#include <iostream>

void MainMenu::Init() {
	Scene::Init();

	std::cout << "Inicializando MainMenu" << std::endl;

	menuTitle.SetText("BALL-ROOM");
	menuTitle.SetPosition(Vector3D(4, 7, 2));
	gameObjects.push_back(&menuTitle);

	description.SetText("!!!Consigue 12 corazones sin chocarte con las pelotas enemigas!!!");
	description.SetPosition(Vector3D(-1, 5, 2));
	gameObjects.push_back(&description);

	instruction.SetText("Instrucciones: pulsa la tecla 'SPACE' para cambiar el movimiento a la direccion contraria.");
	instruction.SetPosition(Vector3D(-5.5, 4, 2));
	gameObjects.push_back(&instruction);

	start.SetText("Pulsa la tecla 'E' para comenzar el juego.");
	start.SetPosition(Vector3D(-0.2, 2, 2));
	gameObjects.push_back(&start);
	
}
void MainMenu::Render() {
	for (auto& gameObject : gameObjects) {
		gameObject->Render();
	}
}

void MainMenu::ProcessKeyPressed(unsigned char key, int px, int py) {
	if (key == 'e') {
		ready = true;
	}
}

int MainMenu::ChangeScene() {
	if (ready) {
		return 1; //Devuelve el índice de la escena (en sceneCollection) a la que se quiere cambiar (gameScene)
	}
	else {
		return -1; //No se cambia de escena
	}
}


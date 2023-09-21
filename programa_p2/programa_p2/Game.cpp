#include <iostream>
#include "Game.h"
#include "GameScene.h"
#include "RankingScene.h";
using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "Tecla pulsada: " << key << endl;
	this->currentScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
	this->currentScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	cout << "Clic del mouse: " << button << " " << state << " " << x << " " << y << endl;
	this->currentScene->ProcessMouseClick(button, state, x, y);
}

void Game::Init()
{
	cout << "GAME INITIALIZATION" << endl;

	MainMenu* mainMenu = new MainMenu(); //Inicializa mainmenu
	mainMenu->Init();
	RankingScene* rankingScene = new RankingScene(); //Inicializa rankingScene
	rankingScene->Init();
	GameScene* gameScene = new GameScene(rankingScene); //gameScene se convierte en rankingScene
	gameScene->Init();


	sceneCollection.push_back(mainMenu); //sceneCollection[0]
	sceneCollection.push_back(gameScene); //sceneCollection[1]
	sceneCollection.push_back(rankingScene); //sceneCollection[2]

	currentScene = sceneCollection[0]; //Escena con la que comienza el programa

}

void Game::Render()
{
	this->currentScene->Render();
}

void Game::Update(const float& time)
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->currentScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
	
	CheckForSceneChange();
}

void Game::CheckForSceneChange() {
	if (currentScene->ChangeScene() > -1) {
		currentScene = sceneCollection[currentScene->ChangeScene() ];
	}
}
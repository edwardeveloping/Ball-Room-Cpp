#include "GameScene.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include <chrono>
#include <ctime>


#pragma warning(disable:4996)

using namespace std;

void GameScene::Init()
{
	Scene::Init();

	srand(time(NULL));
	SpawnCollectable();
}

void GameScene::Update(const float& time) {
	Scene::Update(time);

	UpdateCollisions();
}

//----------------------------------- COLISIONES -----------------------------------

void GameScene::UpdateCollisions() {
	Collectable* collectableCollided = CheckCollectablesCollisions();
	if (collectableCollided != NULL)//El jugador recoge un coleccionable
	{
		UpdatePunctuation();
		RemoveCollectable(collectableCollided);
		SpawnCollectable();
		++nCollectables;
		CheckForSpawnEnemy();
		CheckForVictoryCondition();
	}

	if (CheckEnemiesCollisions()) { //si colisiona con un enemigo el jugador pierde
		//cout << "Has perdido" << endl;
		EndGame(false);
	}
}
Collectable* GameScene::CheckCollectablesCollisions() {

	for (Collectable* coll : collectables) {
		if (mainBall->CheckCollisionWithSphere(coll)) {
			//cout << "Ha habido colisión" << endl;
			
			return coll;
		}
	}
	return NULL;
}

Ball* GameScene::CheckEnemiesCollisions() {
	for (Ball* enemy : enemies) {
		if (mainBall->CheckCollisionWithSphere(enemy)) {
			return enemy;
		}
	}
	return NULL;
}

//------------------------------------- SPAWNS -------------------------------------

void GameScene::SpawnCollectable() {
	Collectable* collToAdd = new Collectable(GetRandomPosition());
	collectables.push_back(collToAdd);
	gameObjects.push_back(collToAdd);

	cout << "Coleccionable spawneado" << endl;
}

void GameScene::SpawnEnemy() {
	Ball* enemyToAdd = new Ball(GetRandomPosition(), Color(5, 5, 5), GetRandomSpeed());
	enemies.push_back(enemyToAdd);
	gameObjects.push_back(enemyToAdd);
}

void GameScene::CheckForSpawnEnemy() {
	if (nCollectables == pow(enemies.size()+2, 2)) { //RATIO DE APARICION DE ENEMIGOS, aparecerán enemigos acada 4, 9, 16... colecionables recogidos
		cout << "Numero de coleccionables: " << nCollectables << ", enemigo generado." << endl;
		SpawnEnemy();
	}
}

void GameScene::RemoveCollectable(Collectable* collToRemove) {
	for (int i = 0; i < collectables.size(); i++) { //Eliminarlo en collectables
		if (collectables[i] == collToRemove) {
			collectables.erase(collectables.begin() + i);
			//Se hará el delete del objeto en RemoveGameObject()
		}
	}
	RemoveGameObject(collToRemove);
}

Vector3D GameScene::GetRandomPosition() {
	float minX = 0;
	float maxX = 10;
	float minY = 0;
	float maxY = 8;

	float randX = minX + static_cast<float>(rand()) * static_cast<float>(maxX - minX) / RAND_MAX;
	float randY = minX + static_cast<float>(rand()) * static_cast<float>(maxY - minY) / RAND_MAX;
	//cout << "(" << randX << ", " << randY << ")" << std::endl;
	return Vector3D(randX, randY, 10);
}

Vector3D GameScene::GetRandomSpeed() {
	return permitedVelocities[rand() % permitedVelocities.size()]; //Devuelve una velocidad aleatoria
}

//----------------------------------------------------------------------------------

void GameScene::ProcessKeyPressed(unsigned char key, int px, int py) {
	//cout << "Tecla pulsada: " << key << endl;
	//GetRandomPosition();

	if (key == ' ') { //Ejecuta la función 'interact' de mainBall
		mainBall->Interact();
	}
		
}

void GameScene::EndGame(bool win) {

	rankingScene->ConsiderNewPlayer(GeneratePlayerInfo(win));
	
	gameEnded = true;
}

void GameScene::CheckForVictoryCondition() {
	if (nCollectables == nCollectablesForVictory) {
		EndGame(true);
	}
}

int GameScene::ChangeScene() {
	if (gameEnded) {
		return 2; //Devuelve el índice de la escena (en sceneCollection) a la que se quiere cambiar (ranking)
	}
	else {
		return -1; //No se cambia de escena
	}
}

//-----------------------------------PLAYER INFO------------------------------------
//----------------------------------------------------------------------------------

PlayerRankingInfo* GameScene::GeneratePlayerInfo(bool win)
{
	return new PlayerRankingInfo(CalculateGameTime(), win);

}

int GameScene::CalculateGameTime() {
	return int(clock() - begin_time) / CLOCKS_PER_SEC;
}

string& GameScene::CalculateGameDate() {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%d/%m/%Y");
	string date = oss.str();

	return date;
}

//----------------------------------------------------------------------------------
void GameScene::UpdatePunctuation() {
	punctuation->SetText("Coleccionables: " + to_string(nCollectables+1));
}

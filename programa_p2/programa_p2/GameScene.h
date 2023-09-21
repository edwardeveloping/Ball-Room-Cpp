#pragma once
#include "Scene.h"
#include "MainBall.h"
#include "Collectable.h"
#include <vector>
#include "PlayerRankingInfo.h"
#include "RankingScene.h"

using namespace std;

class GameScene : public Scene
{
private:
	MainBall* mainBall; //Pelota principal que controla el jugador
	vector<Ball*> enemies; // Pelotas enemigas que el jugador debe evitar
	vector<Collectable*> collectables; //Coleccionables que el jugador debe recoger

	RankingScene* rankingScene;

	bool gameEnded = false; //si el juego ha acabado
	int nCollectables; //numero de coleccionables que ha recogido el jugador.
	int nCollectablesForVictory = 12; //el número de coleccionables que tiene que conseguir el jugador para ganar

	vector <Vector3D> permitedVelocities; //Vector con las posibles velocidades que pueden tomar los objetos de la escena

	const clock_t begin_time = clock();

	Text* punctuation;

public:
	GameScene(RankingScene* rankingSceneArg) : rankingScene(rankingSceneArg) {

		permitedVelocities.push_back(Vector3D(0.1, 0.1, 0));
		permitedVelocities.push_back(Vector3D(-0.1, 0.1, 0));
		permitedVelocities.push_back(Vector3D(0.1, -0.1, 0));
		permitedVelocities.push_back(Vector3D(-0.1, -0.1, 0));

		punctuation = new Text(Vector3D(3, -2, 2), "Coleccionables: 0");
		gameObjects.push_back(punctuation);

		mainBall = new MainBall(Vector3D(2, 0, 10), Color(2, 0, 0), Vector3D(0.1, 0.1, 0));
		gameObjects.push_back(mainBall);
	}

	void Init();
	void Update(const float& time);

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void EndGame(bool); //Acaba la partida, recibe true si ha sido una victoria y false si ha sido una derrota
	void CheckForVictoryCondition();
	PlayerRankingInfo* GeneratePlayerInfo(bool); //Genera la información del jugador, recibe true si ha ganado, false si ha perdido

	void UpdateCollisions();
	Collectable* CheckCollectablesCollisions();
	Ball* CheckEnemiesCollisions();

	void SpawnEnemy();
	void CheckForSpawnEnemy();
	void SpawnCollectable();
	void RemoveCollectable(Collectable*);

	Vector3D GetRandomPosition();
	Vector3D GetRandomSpeed();

	int CalculateGameTime();
	string& CalculateGameDate();
	void UpdatePunctuation();

	int ChangeScene();
};


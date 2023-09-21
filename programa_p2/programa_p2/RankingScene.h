#pragma once
#include "Scene.h"
#include "Ranking.h"

class RankingScene : public Scene
{
private:
	
	Text* title;

	Ranking* ranking;

	Text* summary;

public:
	RankingScene() { 
		ranking = new Ranking(Vector3D(-0.5, 7, 2));
		gameObjects.push_back(title = new Text(Vector3D(-0.5, 10, 2), "RANKING DE VICTORIAS"));
		gameObjects.push_back(summary = new Text(Vector3D(-3, 2, 2), ""));
	}

	void ConsiderNewPlayer(PlayerRankingInfo* newPlayerInfo);

	int ChangeScene();

};


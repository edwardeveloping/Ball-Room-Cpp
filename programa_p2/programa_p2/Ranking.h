#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "PlayerRankingInfo.h"
#include "Text.h"

using namespace std;

class Ranking
{
private:
	vector <PlayerRankingInfo*> playersInfo;
	vector <Solid*> playersDisplay;

	Vector3D rankingPosition;

public:

	Ranking(Vector3D positionArg = Vector3D(-0.5, 7, 2)) : rankingPosition(positionArg) {
		/*playersInfo.push_back(new PlayerRankingInfo(12));
		playersInfo.push_back(new PlayerRankingInfo(10));
		playersInfo.push_back(new PlayerRankingInfo(9));
		playersInfo.push_back(new PlayerRankingInfo(7));*/
		
		LoadRanking();
		SortByGameTime();
		GenerateTexts(rankingPosition);
	}

	vector<Solid*> GetPlayersDisplay() { return playersDisplay; }

	void SortByGameTime();
	void AddPlayer(PlayerRankingInfo* newPlayerInfo); //Añade un jugador al ranking

	void GenerateTexts(Vector3D position);

	void LoadRanking();
	void SaveRanking();
};


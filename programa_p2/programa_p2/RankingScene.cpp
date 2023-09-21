#include "RankingScene.h"

void RankingScene::ConsiderNewPlayer(PlayerRankingInfo* newPlayerInfo)
{
	cout << newPlayerInfo->GetName() << ", has completado el juego en " << newPlayerInfo->GetGameTime();

	if (!newPlayerInfo->GetVictory()) { //Si no ha ganado
		summary->SetText("Lo siento, " + newPlayerInfo->GetName() + ", consigue una victoria para entrar al ranking!");
	}
	else {
		summary->SetText("Enhorabuena, " + newPlayerInfo->GetName() + ", has superado el juego en " + to_string(newPlayerInfo->GetGameTime()) + " segundos.");
		ranking->AddPlayer(newPlayerInfo);
	}

	AddGameObjectVector(ranking->GetPlayersDisplay()); 

	ranking->SaveRanking();
}

int RankingScene::ChangeScene() {
	return -1;
}
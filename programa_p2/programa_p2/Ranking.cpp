#include "Ranking.h"
using namespace std;



void Ranking::SortByGameTime()
{
	for (int i = 0; i < playersInfo.size(); i++) {
		for (int j = i + 1; j < playersInfo.size(); j++) {
			if (playersInfo[i]->GetGameTime() > playersInfo[j]->GetGameTime()) {

				swap(playersInfo[i], playersInfo[j]);
			}
		}
	}

}

void Ranking::AddPlayer(PlayerRankingInfo* newPlayerInfo)
{
	playersInfo.push_back(newPlayerInfo);
	SortByGameTime();
	playersInfo.pop_back(); //Se debe hacer un delete

	playersDisplay.clear(); //Actualiza el texto 
	GenerateTexts(rankingPosition);
}

void Ranking::GenerateTexts(Vector3D position)
{
	float margin = 0.5;
	float totalMargin = 0;

	for (PlayerRankingInfo* info : playersInfo) {
		playersDisplay.push_back(
			new Text(Vector3D(position.GetX(), position.GetY() + totalMargin, position.GetZ()),
				info->GetInfo())
		);
		totalMargin -= margin;
		
	}

	cout << "Tamanio playersDisplay: " << playersDisplay.size() << endl;
}

void Ranking::SaveRanking()
{
	try {
		ofstream out("rankingsFile.txt");

		for (PlayerRankingInfo* info : playersInfo) {
			out << "-" << info->GetName() << endl;
			out << info->GetGameTime() << endl;
		}

		out.close();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void Ranking::LoadRanking() {
	try {
		string str;
		string pjName; //nombre del personaje
		int pjGT; //Game Time del personaje

		ifstream in("rankingsFile.txt", ios::in); //Abrimos el archivo en modo lectura

		while (!in.eof()) { //recorrer todo el archivo
			getline(in, str);
			
			if (str[0] == '-') { //Es un nombre
				pjName = str.substr(1, str.size() - 1);
				
				getline(in, str); //inmediatamente obtiene la siguiente línea, el tiempo de juego
				pjGT = stoi(str);

				playersInfo.push_back(new PlayerRankingInfo(pjName, pjGT));
			}
		}

		in.close();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

class PlayerRankingInfo
{
private:
	string name;
	int gameTime;
	bool victory; //Si consiguió superar el juego

	vector<string> biblicalNames{ "Adam", "Eve", "Noah", "Abraham", "Isaac", "Jacob", "Joseph", //Vector generado utilizando CHAT GDP
		"Moses", "Aaron", "Joshua", "Samuel", "David", "Solomon", "Isaiah", "Jeremiah", "Ezekiel",
		"Daniel", "Hosea", "Joel", "Amos", "Obadiah", "Jonah", "Micah", "Nahum", "Habakkuk", "Zephaniah",
		"Haggai", "Zechariah", "Malachi" };
public:

	PlayerRankingInfo(string nameArg, int gameTimeArg) : name(nameArg), gameTime(gameTimeArg) {}

	PlayerRankingInfo(int gameTimeArg, bool victoryArg) :  gameTime(gameTimeArg), victory(victoryArg) {
		name = PickRandomName();
	}

	string GetName() { return name; }
	int GetGameTime() { return gameTime; }
	bool GetVictory() { return victory; }
	void SetGameTime(int gameTimeToSet) { gameTime = gameTimeToSet; }
	void SetName(string nameToSet) { name = nameToSet; }

	string GetInfo() {
		return name + " -------- " + " Tiempo de juego: " + to_string(gameTime) + " segundos.";
	}

	string PickRandomName() {
		return biblicalNames[rand() % biblicalNames.size()];
	}
};


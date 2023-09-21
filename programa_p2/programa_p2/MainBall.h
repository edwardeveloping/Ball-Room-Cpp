#pragma once
#include "Ball.h"
#include "Interactable.h"


class MainBall :public Ball, public Interactable //Pelota principal que controla el jugador
{
public:

	MainBall(Vector3D positionArgument, Color colorArgument, Vector3D orientationSpeedArgument) :
		Ball(positionArgument, colorArgument, orientationSpeedArgument) {}

	void Interact(); //Cambia la dirección de la pelota
};


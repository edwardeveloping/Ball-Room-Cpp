#pragma once
#include "Sphere.h"
class Ball: public Sphere //Una pelota que se mueve en el espacio del juego
{
public:
	Ball(Vector3D positionArgument, Color colorArgument, Vector3D speedARgument) :
		Sphere(positionArgument, colorArgument, speedARgument) {}
};


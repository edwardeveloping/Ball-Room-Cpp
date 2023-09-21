#include "MainBall.h"

void MainBall::Interact()
{
	//Cambia la dirección del movimiento al contrario en el eje Y del que esté
	speed = Vector3D(speed.GetX(), speed.GetY() * -1, speed.GetZ());
}

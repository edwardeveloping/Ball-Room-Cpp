#include "MainBall.h"

void MainBall::Interact()
{
	//Cambia la direcci�n del movimiento al contrario en el eje Y del que est�
	speed = Vector3D(speed.GetX(), speed.GetY() * -1, speed.GetZ());
}

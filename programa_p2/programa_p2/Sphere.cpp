#include "Sphere.h"
#include <cmath>

void Sphere::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	this->GetIsTransparent() ? glutWireSphere(GetRadius(), GetSlices(), GetSlacks()) : glutSolidSphere(GetRadius(), GetSlices(), GetSlacks());
	glPopMatrix();
}

float Sphere::Distance(Sphere* s) {
	return sqrt(
		pow(position.GetX() - s->GetPosition().GetX(), 2) +
		pow(position.GetY() - s->GetPosition().GetY(), 2) +
		pow(position.GetZ() - s->GetPosition().GetZ(), 2)
	);
}

bool Sphere::CheckCollisionWithSphere(Sphere* s) {
	return this->Distance(s) < (GetRadius() + s->GetRadius()); //Colisionan cuando la suma de sus radios es menor que la distancia entre ellas
}
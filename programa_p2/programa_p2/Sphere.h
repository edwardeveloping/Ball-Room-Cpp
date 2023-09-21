#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Sphere : public Solid
{
private:

	float radius;
	int slices;
	int slacks;

public:

	Sphere() : Solid(Vector3D(0.0, 0.0, -0.2), Color(0.7, 0.2, 0.5), Vector3D(0.0, 0.0, 0.0)),
		radius(0.6), slices(200), slacks(10) {}

	Sphere(Vector3D positionArgument, Color colorArgument, Vector3D speedArgument) :
		Solid(positionArgument, colorArgument, speedArgument),
		radius(0.6), slices(200), slacks(10) {}

	Sphere(Vector3D positionArgument, Color colorArgument,float radiusArgument):
		Solid(positionArgument, colorArgument),
		radius(radiusArgument), slices(200), slacks(10) {}

	inline float GetRadius() const { return this->radius; }
	inline int GetSlices() const { return this->slices; }
	inline int GetSlacks() const { return this->slacks; }

	inline void SetRadius(float radiusToSet) { this->radius = radiusToSet; }
	inline void SetSlices(int slicesToSet) { this->slices = slicesToSet; }
	inline void SetSlacks(int slacksToSet) { this->slacks = slacksToSet; }

	bool CheckCollisionWithSphere(Sphere* s); //Calcula si existe una colisión entre esta esfera y la esfera dada
	float Distance(Sphere* s);

	void Render();
};


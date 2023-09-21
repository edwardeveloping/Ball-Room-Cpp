#pragma once
#include "Triangle.h"
#include <GL/glut.h>
#include <vector>

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> triangles;
public:
	Model() {}

	Model(Vector3D position, Color color, Vector3D orientation) : Solid(position, color, Vector3D(0,0,0), orientation) {}

	void AddTriangle(Triangle triangle);
	void PaintColor(Color color);
	void Clear();

	void Render();


};


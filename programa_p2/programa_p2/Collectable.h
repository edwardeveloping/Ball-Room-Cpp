#pragma once
#include "Sphere.h"
#include "Model.h"
#include "ModelLoader.h"
class Collectable : public Sphere //Objetos que el jugador debe recoger, de momento son Teapots, PROVISIONAL
{
	/*
private:
	float radius;
	Color color;
public:
	//Collectable(Vector3D position) : Teapot(position , size = 0.4) {}
	Collectable(Vector3D position) : Sphere(position, color = Color(2, 1, 9), radius = 0.3) {}
};*/

private:
	float radius;
	Color color;

	ModelLoader* loader;
	Model* heart;
public:
	
	Collectable(Vector3D position) : Sphere(position, color = Color(2, 1, 9), radius = 0.3) {
	
		loader = new ModelLoader(0.65);
		heart = new Model();
		//loader->Clear();
		loader->LoadModel("..\\..\\3dModels\\heart.obj");
		*heart = loader->GetModel();
		heart->SetPosition(position);
		heart->SetOrientation( Vector3D(0, 90, 0) );

		heart->PaintColor(Color(2, 1, 0.2));
	}
	
	void Render();
};
#include "Scene.h"


void Scene::Init()
{
	generateBoundry();
}

void Scene::Update(const float& time)
{
	this->camera.Update(time);

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(time);
	}

	this->checkBoundary();

}

void Scene::Render()
{
	this->camera.Render();

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void Scene::generateBoundry() {
	
	camera.SetPosition(Vector3D(this->boundary.GetX() / 2, this->boundary.GetY() / 2, this->boundary.GetZ() * 1.8));

	if (this->GetDrawVertexes())
	{
		Cube* point1 = new Cube();
		point1->SetColor(Color(0, 0, 1));
		point1->SetPosition(Vector3D(0, 0, 0));
		point1->SetSize(0.2);
		this->AddGameObject(point1);

		Cube* point2 = new Cube();
		point2->SetColor(Color(0, 0, 1));
		point2->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, 0));
		point2->SetSize(0.2);
		this->AddGameObject(point2);

		Cube* point3 = new Cube();
		point3->SetColor(Color(0, 0, 1));
		point3->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), 0));
		point3->SetSize(0.2);
		this->AddGameObject(point3);

		Cube* point4 = new Cube();
		point4->SetColor(Color(0, 0, 1));
		point4->SetPosition(Vector3D(0, this->GetBoundary().GetY(), 0));
		point4->SetSize(0.2);
		this->AddGameObject(point4);

		Cube* point5 = new Cube();
		point5->SetColor(Color(0, 0, 1));
		point5->SetPosition(Vector3D(0, this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		point5->SetSize(0.2);
		this->AddGameObject(point5);

		Cube* point6 = new Cube();
		point6->SetColor(Color(0, 0, 1));
		point6->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		point6->SetSize(0.2);
		this->AddGameObject(point6);

		Cube* point7 = new Cube();
		point7->SetColor(Color(0, 0, 1));
		point7->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, this->GetBoundary().GetZ()));
		point7->SetSize(0.2);
		this->AddGameObject(point7);

		Cube* point8 = new Cube();
		point8->SetColor(Color(0, 0, 1));
		point8->SetPosition(Vector3D(0, 0, this->GetBoundary().GetZ()));
		point8->SetSize(0.2);
		this->AddGameObject(point8);
	}

	if (this->drawBox)
	{
		Cuboid* floor = new Cuboid();
		floor->SetHeight(0.01);
		floor->SetWidth(this->GetBoundary().GetZ());
		floor->SetLength(this->GetBoundary().GetX());
		floor->SetColor(Color(0.5, 0.8, 1));
		floor->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, 0, this->GetBoundary().GetZ() / 2));
		floor->SetIsTransparent(true);
		this->AddGameObject(floor);

		Cuboid* ceil = new Cuboid();
		ceil->SetHeight(0.01);
		ceil->SetWidth(this->GetBoundary().GetZ());
		ceil->SetLength(this->GetBoundary().GetX());
		ceil->SetColor(Color(0.5, 0.8, 1));
		ceil->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY(), this->GetBoundary().GetZ() / 2));
		ceil->SetIsTransparent(true);
		this->AddGameObject(ceil);

		Cuboid* back = new Cuboid();
		back->SetHeight(this->GetBoundary().GetY());
		back->SetWidth(0.01);
		back->SetLength(this->GetBoundary().GetX());
		back->SetColor(Color(0.6, 0.2, 0.2));
		back->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY() / 2, 0));
		back->SetIsTransparent(true);
		this->AddGameObject(back);

		Cuboid* left = new Cuboid();
		left->SetHeight(this->GetBoundary().GetY());
		left->SetWidth(this->GetBoundary().GetZ());
		left->SetLength(0.01);
		left->SetColor(Color(0.2, 0.2, 0.6));
		left->SetPosition(Vector3D(0, this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ() / 2));
		left->SetIsTransparent(true);
		this->AddGameObject(left);

		Cuboid* right = new Cuboid();
		right->SetHeight(this->GetBoundary().GetY());
		right->SetWidth(this->GetBoundary().GetZ());
		right->SetLength(0.01);
		right->SetColor(Color(0.7, 0.9, 0.5));
		right->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ() / 2));
		right->SetIsTransparent(true);
		this->AddGameObject(right);
	}
}

void Scene::checkBoundary()
{
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		if (this->gameObjects[idx]->GetPosition().GetX() < 0 || this->gameObjects[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			this->gameObjects[idx]->SetSpeed(Vector3D(-1 * this->gameObjects[idx]->GetSpeed().GetX(),
				this->gameObjects[idx]->GetSpeed().GetY(),
				this->gameObjects[idx]->GetSpeed().GetZ()));
		}

		if (this->gameObjects[idx]->GetPosition().GetY() < 0 || this->gameObjects[idx]->GetPosition().GetY() > this->boundary.GetY())
		{
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX(),
				-1 * this->gameObjects[idx]->GetSpeed().GetY(),
				this->gameObjects[idx]->GetSpeed().GetZ()));
		}

		if (this->gameObjects[idx]->GetPosition().GetZ() < 0 || this->gameObjects[idx]->GetPosition().GetZ() > this->boundary.GetZ())
		{
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX(),
				this->gameObjects[idx]->GetSpeed().GetY(),
				-1 * this->gameObjects[idx]->GetSpeed().GetZ()));
		}
	}
}

void Scene::RemoveGameObject(Solid* gameObjectToRemove) {
	for (int i = 0; i < gameObjects.size(); i++) {
		if (gameObjects[i] == gameObjectToRemove) {
			gameObjects.erase(gameObjects.begin() + i);
			delete gameObjectToRemove;
		}
	}
}
void Scene::AddGameObjectVector(vector<Solid*> solidVector)
{
	for (Solid* solidToAdd : solidVector) {
		gameObjects.push_back(solidToAdd);
	}
}
void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {}

void Scene::ProcessMouseMovement(int x, int y) {}

void Scene::ProcessMouseClick(int button, int state, int x, int y){}
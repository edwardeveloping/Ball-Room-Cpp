#pragma once
#include <vector>
#include "Text.h"
#include "Cube.h"
#include "Sphere.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Cylinder.h"

using namespace std;

class Scene
{
protected:

	Camera camera;
	vector<Solid*> gameObjects;
	Vector3D boundary;

	bool drawVertexes;
	bool drawBox;

	void generateBoundry();
	void checkBoundary();

public:
	Scene(Vector3D boundaryArgument = Vector3D(10, 8, 9.5), bool drawVertexesArgument = false, bool drawBoxArgument = false) : 
		boundary(boundaryArgument), drawVertexes(drawVertexesArgument), drawBox(drawBoxArgument) {};

	inline Vector3D GetBoundary() const { return this->boundary; }
	inline void SetBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }
	inline bool GetDrawVertexes() const { return this->drawVertexes; }
	inline void SetDrawVertexes(const bool& drawVertexesToSet) { this->drawVertexes = drawVertexesToSet; }
	inline bool GetDrawBox() const { return this->drawBox; }
	inline void SetDrawBox(const bool& drawBoxToSet) { this->drawBox = drawBoxToSet; }

	inline void AddGameObject(Solid* gameObject) { this->gameObjects.push_back(gameObject); }

	void Init();
	void Render();
	virtual void Update(const float& time);

	virtual void ProcessKeyPressed(unsigned char key, int px, int py); //Virtual porque cada escena implementará el input de forma diferente, no me funcionaba
	virtual void ProcessMouseMovement(int x, int y);
	virtual void ProcessMouseClick(int button, int state, int x, int y);

	void RemoveGameObject(Solid* gameObjectToRemove); //Dado un Puntero elimina el objeto de gameObjects que coincide con dicho puntero
	void AddGameObjectVector(vector<Solid*> solidVector);

	virtual int ChangeScene() = 0;
};


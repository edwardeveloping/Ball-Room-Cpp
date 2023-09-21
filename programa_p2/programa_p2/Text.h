#pragma once
#include <string>
#include "Solid.h"
#include <GL/glut.h>
using namespace std;


class Text : public Solid
{
private:
	string text;
public:
	Text(){}
	Text(Vector3D positionArg, string textArg) : text(textArg), Solid(positionArg){}

	void SetText(string _text);
	void Render();
};

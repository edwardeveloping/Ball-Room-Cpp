#include "Text.h"
#include <string>

void Text::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glRasterPos3d(0, 0, 0);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c); //El primer valor es la fuente, se puede modificar por otra
	glPopMatrix();
}
void Text::SetText(string _text) {
	text = _text;
}

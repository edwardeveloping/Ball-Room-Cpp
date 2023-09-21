#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Cuboid : public Solid
{
private:
    float length;
    float height;
    float width;
public:

    Cuboid(float nLength = 0.4f, float nHeight = 0.2f, float nWidth = 0.1f, Vector3D nPos = Vector3D(0, 0, 0), Color nColor = Color(0.2, 0.5, 0.1) ) :
        length(nLength), height(nHeight), width(nWidth), Solid(nPos, nColor) {}

    inline float GetLength() const { return this->length; }
    inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
    inline float GetHeight() const { return this->height; }
    inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
    inline float GetWidth() const { return this->width; }
    inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

    void Render();
};


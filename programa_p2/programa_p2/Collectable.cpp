#include "Collectable.h"

void Collectable::Render() {
	Sphere::Render();

	heart->Render();
}
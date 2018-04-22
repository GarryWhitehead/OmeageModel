#include "OMFConverter.h"



OMFConverter::OMFConverter()
{
}


OMFConverter::~OMFConverter()
{
}

std::string OMFConverter::Material::GetMaterialType(MatType type) const
{
	std::string filename;
	switch (type) {
	case MatType::MAT_DIFFUSE:
		filename = Map.albedo;
		break;
	case MatType::MAT_NORMAL:
		filename = Map.normal;
		break;
	}
	return filename;
}

bool OMFConverter::Material::hasTexture(MatType type) const
{
	switch (type) {
	case MatType::MAT_DIFFUSE:
		return !Map.albedo.empty();
		break;
	case MatType::MAT_NORMAL:
		return !Map.normal.empty();
		break;
	}
}

bool OMFConverter::Material::hasTexture() const
{
	// all materials must have a diffuse texture
	if (Map.albedo.empty()) {

		return false;
	}

	return true;
}
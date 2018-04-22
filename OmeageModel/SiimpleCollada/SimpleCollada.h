#pragma once
#include "XMLparse.h"
#include "OMFConverter.h"
#include <vector>
#include <string>
#include "SiimpleCollada/ColladaSkeleton.h"
#include "SiimpleCollada/ColladaVertices.h"
#include "SiimpleCollada/ColladaMaterials.h"
#include "SiimpleCollada/ColladaAnimation.h"

class SimpleCollada
{
public:

	struct SceneData
	{
		ColladaAnimation* animation;
		ColladaSkeleton *skeleton;
	};

	SimpleCollada();
	~SimpleCollada();

	bool OpenColladaFile(std::string filename);
	void ImportColladaData(OMFConverter::ModelInfo *model);
	
private:

	XMLparse *m_xmlParse;

	SceneData *m_sceneData;
};




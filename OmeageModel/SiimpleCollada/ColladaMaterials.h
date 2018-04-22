#pragma once
#include "SiimpleCollada/XMLparse.h"
#include "OMFConverter.h"

class ColladaMaterials
{

public:

	ColladaMaterials(XMLparse *parse);
	~ColladaMaterials();

	void ImportMaterials(OMFConverter::ModelInfo *model);
	void ImportLibraryMaterials(OMFConverter::ModelInfo *model);
	void ImportLibraryImages();


private:

	XMLparse *m_xmlParse;

	std::vector<std::string> libraryImageData;

};


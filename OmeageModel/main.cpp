#include "Objector/objector.h"
#include "SiimpleCollada/SimpleCollada.h"
#include "OMFConverter.h"
#include "serialisation.h"
#include <iostream>

# define MIN_ARGC 3

void DisplayUsage(std::string arg)
{

	std::cerr << "Usage: " << arg << "Options: \n" <<
		"-s -- source model filename \n" <<
		"-d -- destination converted OMF filename \n" <<
		"-f -- source file model format - can be one of the following: \n" <<
		"OBJ -- wavefront .obj model source file format \n" <<
		"DAE -- collada model source file format \n";
}

int main(int argc, char *argv[])
{
	// arguments for command line call
	// 1. filename of model file to convert
	// 2. destination filename and dir
	// 3. model file typpe : -OBJ, -DAE
	// 4. 

	if (argc < MIN_ARGC) {
		std::cerr << "Usage: " << argv[0] << "source filename / destination filename / model file type: supported model formats -OBJ objector, -DAE collada \n";
		return 1;
	}

	std::string source;
	std::string destination;
	std::string format;

	for (int c = 0; c < argc; ++c) {

		std::string arg = argv[c];
		if (arg == "-h") {
			DisplayUsage(argv[0]);
			return 0;
		}
		if (arg == "-s") {

			if (c + 1 < argc) {
				source = argv[c++];
			}
		}
		else {
			std::cerr << "No source filename found.\n";
			return 1;
		}
		if (arg == "-d") {

			if (c + 1 < argc) {
				destination = argv[c++];
			}
		}
		else {

			std::cerr << "No destination filename found.\n";
			return 1;
		}
		if(arg == "-f") {

			if (c + 1 < argc) {
				format = argv[c++];
			}
		}
		else {

			std::cerr << "No destination filename found.\n";
			return 1;
		}
	}

	// import the model using the correct importer stated by the argumnet line and convert to a OMF file
	if (format == "OBJ") {

		Objector *p_objector = new Objector();
		OMFConverter::ModelInfo *model = new OMFConverter::ModelInfo();

		p_objector->ImportObjFile(source, model);

		Archiver *p_archive = new Archiver();

		p_archive->OpenFile(destination, SaveMode::SAVE_TEXT, FileMode::FILE_OUT);
		p_archive->SerialiseModelData(p_arhcive, *model, Archiver::var_info(""));
	}

	if (format == "DAE") {

		SimpleCollada *p_collada = new SimpleCollada();
		OMFConverter::ModelInfo model;

		p_collada->ImportColladaData(source, model);

	}
	else {

		std::cerr << "Unsupported model format. Supported formats: OBJ (.obj) and DAE (collada) \n";
		return 1;
	}
}
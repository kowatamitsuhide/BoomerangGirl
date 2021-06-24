#include"LoadCSV.h"
#include<fstream>
#include<sstream>
#include<codecvt>
#include<map>
#include<stdlib.h>

LoadCSV::LoadCSV()
{

}

LoadCSV::~LoadCSV()
{

}

void LoadCSV::LoadStatus(string filename)
{
	FILE* file;
	file = fopen(filename.c_str(), "r");

	char buffer[512];

	char _char_status_name[256];

	while(fgets(buffer, sizeof(buffer), file) != NULL)
	{
		float _data = 0.0f;

		sscanf(buffer, "%s %f", &_char_status_name, &_data);
		std::string _status_name = _char_status_name;
		_status.insert(make_pair(_status_name, _data));
	}

	fclose(file);
}
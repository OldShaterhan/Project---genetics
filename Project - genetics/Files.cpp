#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

#include "Files.h"

bool loadConfig(std::string _filename, int *_genSize, int *_gensNumber, int *_mutationChance)
{
	std::ifstream cfgFile;
	std::string exception;
	cfgFile.open(_filename);
		if (cfgFile.good()) {
			std::cout << "Loading config..." << std::endl;
			cfgFile >> *_genSize
				>> *_gensNumber
				>> *_mutationChance;
			if (*_mutationChance > 100|| *_mutationChance <0)
				throw exception = "Mutation probability value is greater than 100% or less than 0%\n";
			if (*_genSize <2)
				throw exception = "Generation size (Number of members) smaller than 2!\n";
			if (*_gensNumber < 1)
				throw exception = "Less than one generation to be created!\n";

		}
		else
		{
			std::cout << "Config unaccessible..." << std::endl;
			return 1;
		}
	cfgFile.close();
}

bool loadParams(std::string _filename, std::vector<double> params[3]) {
	std::ifstream paramsFile;
	paramsFile.open(_filename);
	if (paramsFile.good()) {
		std::cout << "Loading parameters..."<<std::endl;
		while (1) {
			double _params[3];
			char delim;
			try {


				paramsFile >> _params[0] >> delim >> _params[1] >> delim >> _params[2];

			}
			catch (...) {
				std::cout << "An error occured. params.csv file is corrupted.";
			}
			params[0].push_back(_params[0]);
			params[1].push_back(_params[1]);
			params[2].push_back(_params[2]);

			
			if (paramsFile.eof()) break;
		}

	}
	else
	{
		std::cout << "Parameters unaccessible...";
		return 1;
	}

	paramsFile.close();
}

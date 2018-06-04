#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <random>

#include "Files.h"
#include "Functions.h"
#include "Generations.h"
#include "Generations_o.h"


int main() {
	int genSize=-1;							//generations size
	int gensNumber=-1;						//generations number
	int mutationChance=-1;					//mutation chance
										//default - 1 as to be loaded from file(value used for exceptions)
	std::string cfg_filename = "C://Genetics/config.ini";
	std::string par_filename = "C://Genetics/params.csv";
										//locations of config and params files

	//std::list<Params> params;
	std::vector<double> params[3];
	try {
		if (!loadConfig(cfg_filename, &genSize, &gensNumber, &mutationChance))
		{
			std::cout << "Error while loading config. Exiting..." << std::endl;
			return 1;
		}
	}
	catch (std::string _exception) {
		std::cout << _exception;
		return 1;
	}

	if (!loadParams(par_filename, params))
	{
		std::cout << "Error while loading params. Exiting...";
		return 1;
	}


	//RANDOM ENGINES
	std::mt19937 eng(static_cast<unsigned long>(time(0)));	//used for real x-values
	
	std::srand(time(NULL));									//used for integer values
	//END OF ENGINES

	std::list <GenerationMembersList> GenerationsList;  //initialization of the list
	//for(int i=0;i<3;i++)
	

	GenerationsList.push_back(GenerationMembersList(1, params, genSize, &eng)); //first generation

	std::list<GenerationMembersList>::iterator prev;		//iterator to previous generation (before creating new one)

	std::list<GenerationMember>::iterator best[2];			//iterator for 2 best individuals

	std::vector <double> *mem_ptr;							//pointer to obtain values of x of 2 best individuals

	for (int i = 1; i <= gensNumber; i++)
	{
		prev = GenerationsList.end();
		prev--;
		//(best[0] = prev->getGenMembList().begin());
		best[0] = prev->getGenMembList()->begin();
		best[1] = best[0];
		best[1]++;
		std::cout << "Generation " << i << " 2 best individuals:"<<std::endl;
		for (int j = 0; j <= 1; j++)
		{
			std::cout << j+1 << " one:" << std::endl;
			mem_ptr = best[j]->get_x_values();
			for (int k = 0; k < params->size(); k++) {
				std::cout << "x" << k + 1 << "=" << (*mem_ptr)[k]<<std::endl;
			}
			//std::cout.setf(std::ios::dec, std::ios::basefield);
			std::cout.setf(std::ios::showpoint);
			
			std::cout << "f(x)=" << best[j]->get_f_value()<<std::endl;
		}
		if (i < gensNumber)
		{
			GenerationsList.push_back(GenerationMembersList(params, genSize, best, &eng, mutationChance));
		}
	}


	//std::list<GenerationsList> genList; //other method

//	List<GenerationMembersList> GenerationsList(1,params,genSize);

	
	GenerationsList.clear();

	return 0;
}
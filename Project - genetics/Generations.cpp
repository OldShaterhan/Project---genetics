#include <iostream>
#include <cstdio>
#include <vector>
#include <random>
#include <time.h>
#include <ctime>
#include <list>
#include <Windows.h>
#include "Generations.h"
#include "Functions.h"

GenerationMember::GenerationMember() {

}

double GenerationMember::randVal(double _x_max, std::mt19937 *_eng) {
	//Sleep(100);
	//std::mt19937 eng(static_cast<unsigned long>(time(0)));
	std::uniform_real_distribution<double> dist(0, _x_max);

	return dist(*_eng);
}


bool GenerationMember::operator>(const GenerationMember &other)
{
	return function_value > other.function_value;
}

bool GenerationMember::operator<(const GenerationMember &other)
{
	return function_value < other.function_value;
}

std::vector<double> *GenerationMember::get_x_values()
{
	return &x_values;
}

long double GenerationMember::get_f_value()
{
	return function_value;
}

double GenerationMember::mutate(double _x_max, std::mt19937 *_eng, int _mutationChance)
{
	int chance = rand() % 100;
	if (chance < _mutationChance)
	{
		return randVal(_x_max, _eng);
	}
	return x_values.back();
}

GenerationMember::GenerationMember(bool newlist, std::vector<double> *_params, std::mt19937 *_eng) {
	function_value = 0;
	for (int i = 0; i < _params->size(); i++) {

		double val = randVal(_params[1][i], _eng);
		x_values.push_back(val);

		function_value += _params[0][i] * pow(x_values[i], _params[2][i]);
	}
}


GenerationMember::GenerationMember(std::vector<double> *_params, std::list<GenerationMember>::iterator best[2], std::mt19937 *_eng, int _mutationChance)
{
	function_value = 0;
	for (int i = 0; i < _params->size(); i++) {
		int l = std::rand() % 2; //every individual can get up to 6 values from one parent old method;
		x_values.push_back((*best[l]->get_x_values())[i]);
		
		x_values.back()=mutate(_params[1][i], _eng, _mutationChance);
		function_value += _params[0][i] * pow(x_values[i], _params[2][i]);
	}

}

GenerationMember::~GenerationMember() {
 }



GenerationMembersList::GenerationMembersList() {

}

GenerationMembersList::GenerationMembersList(bool _newList, std::vector<double> *_params, const int &_genSize, std::mt19937 *_eng) {
	
	for (int i = 0; i < _genSize; i++) {
		GenMembList.push_back(GenerationMember(_newList, _params, _eng));
	}
	GenMembList.sort();
	GenMembList.reverse();
}

GenerationMembersList::GenerationMembersList(std::vector<double>* _params, const int &_genSize, std::list<GenerationMember>::iterator _best[2], std::mt19937 *_eng, int _mutationChance)
{
	for (int i = 0; i < _genSize; i++) {
		GenMembList.push_back(GenerationMember(_params,_best, _eng, _mutationChance));
	}
	GenMembList.sort();
	GenMembList.reverse();
}

GenerationMembersList::~GenerationMembersList() {
		GenMembList.clear();
}

std::list<GenerationMember> *GenerationMembersList::getGenMembList()
{
	return &GenMembList;
}

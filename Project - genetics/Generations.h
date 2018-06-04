#pragma once
#include <iostream>
#include <list>
#include <vector>

class GenerationMember {
protected:

	std::vector <double> x_values;				//x values of member

	long double function_value;					//function (individual) value

public:
	GenerationMember();							//default constructor (empty)
	GenerationMember(bool, std::vector<double> *, std::mt19937 *);
												//constructor for first generation
	GenerationMember(std::vector<double> *, std::list<GenerationMember>::iterator[2], std::mt19937 *, int);
												//constructor for second and later members

	~GenerationMember();						//default destructor (empty)
	double randVal(double, std::mt19937 *);		//function that draw x-values for member
	double mutate(double, std::mt19937 *, int); //function that draw if mutation should occur
	bool operator>(const GenerationMember &);	//compare operator, not used at this moment
	bool operator<(const GenerationMember &);	//compare operator

	std::vector <double> *get_x_values();		//function that gets values of x
	long double get_f_value();					//function that gets function value

};


class GenerationMembersList
{
protected:
	std::list<GenerationMember> GenMembList;	//list of members
public:
	GenerationMembersList();					//default constructor (empty)
	GenerationMembersList(bool, std::vector<double> *, const int &, std::mt19937 *);
												//constructor for first generation
	GenerationMembersList(std::vector<double> *, const int &, std::list<GenerationMember>::iterator [2], std::mt19937 *, int);
												//constructor for second and later generations
	~GenerationMembersList();					//default destructor, clears list

	std::list<GenerationMember> *getGenMembList();
												//function that gets list of individuals
};

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool loadConfig(std::string, int *, int *, int *); //loads config.ini file

bool loadParams(std::string, std::vector<double>[3]); //loads params.csv file
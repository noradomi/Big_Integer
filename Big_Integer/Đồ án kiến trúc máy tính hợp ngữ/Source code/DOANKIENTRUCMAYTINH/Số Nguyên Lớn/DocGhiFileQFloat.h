#pragma once
#include<fstream>
#include<vector>
#include<sstream>
#include"QFLoat.h"

vector< vector<string> > docFileQFloat(const char* path);
void ghiFileQFloat(const char *path, vector< vector <string> > input);
#pragma once
#include <string>

using namespace std;

bool readDataFromFile(const string& file, double& S, int& n, double*& w, double*& r); //file reading function declaration
double computeRateOfReturn(const double* w, const double* r, const int n); //rate of interest function declaration
double computeValue(const double* w, const double* r, const int n, const double S); //final value function declaration
void printResults(const double* w, const double* r, const int n, const double S, const double RoR, const double V, const string filename); //writing function declaration

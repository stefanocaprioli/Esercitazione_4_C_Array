#include "Utils.hpp"
#include <string>

using namespace std;

int main()
{
    const string filein = "data.csv";

    double S;
    int n;
    double* w;
    double* r;

    readDataFromFile(filein, S, n, w, r); //reading file function

    double RoR = computeRateOfReturn(w, r, n); //rate of return function

    double V = computeValue(w, r, n, S); //final value function

    const string fileout = "result.txt"; //Writing file name definition
    printResults(w, r, n, S, RoR, V, fileout); //printing on file and console
    //deleting w and r
    delete[] w;
    delete[] r;

    return 0;
}

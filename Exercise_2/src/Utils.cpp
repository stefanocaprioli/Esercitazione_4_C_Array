#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

bool readDataFromFile(const string& filename, double& S, int& n, double*& w, double*& r)
{
    ifstream file(filename); //file opening
    if(file.fail())
    {
        cerr << "File not found" << endl;
        return 1;
    }

    string header;
    stringstream ss;
    string token;

    getline(file, token, ';'); //first line
    getline(file, token); //S value
    ss << token; //insert the value into ss
    ss >> S; //insert ss into S
    ss.clear(); //stringstream emptying

    getline(file, token, ';'); //second line
    getline(file, token); //n value
    ss << token; //insert the value into ss
    ss >> n; //inserit ss into n
    ss.clear(); //stringstream emptying

    getline(file, header); //third line (header)

    w = new double[n]; //array w definition (lenght = n)
    r = new double[n]; //array r definition (lenght = n)
    int count = 0;
    double wtoken;
    double rtoken;
    string line;

    while (count < n)
    {
        getline(file, line, ';');
        ss << line;
        ss >> wtoken;
        w[count] = wtoken;
        ss.clear();

        getline(file, line);
        ss << line;
        ss >> rtoken;
        r[count] = rtoken;
        ss.clear();

        count++;
    }

    return 0;
}

double computeRateOfReturn(const double* w, const double* r, const int n)
{
    double RateOfReturn = 0.0;
    for (int i = 0; i < n; i++) {
        RateOfReturn += w[i] * r[i];
    }
    return RateOfReturn;
}

double computeValue(const double* w, const double* r, const int n, const double S)
{
    double V = 0.0;
    for (int i=0; i<n; i++)
    {
        V += (1 + r[i])*w[i]*S;
    }
    return V;
}

void printResults(const double* w, const double* r, const int n, const double S, const double RoR, const double V, const string filename)
{
    //Printing on a file:
    ofstream outfile(filename); //opening the file in writing mode

    outfile << fixed << setprecision(2); //fixing the precision to 2

    outfile << "S = " << S << ", n = " << n << endl; //writing S and n
    outfile << defaultfloat << "w = [ ";
    for (int i = 0; i<n; i++) //writing w
    {
        outfile << w[i] << " ";
    }
    outfile << "] " << endl << "r = [ ";
    for (int i = 0; i<n; i++) //writing r
    {
        outfile << r[i] << " ";
    }
    outfile << "] " << endl;

    outfile << fixed << setprecision(4) << "Rate of return of the portfolio: " << RoR << endl;
    outfile << setprecision(2) << "V: " << V << endl;

    outfile.close(); //closing file in writing mode

    //Printing on console:
    cout << fixed << setprecision(2);

    cout << "S = " << S << ", n = " << n << endl; //writing S and n
    cout << defaultfloat << "w = [ ";
    for (int i = 0; i<n; i++) //writing w
    {
        cout << w[i] << " ";
    }
    cout << "] " << endl << "r = [ ";
    for (int i = 0; i<n; i++) //writing r
    {
        cout << r[i] << " ";
    }
    cout << "] " << endl;

    cout << fixed << setprecision(4) << "Rate of return of the portfolio: " << RoR << endl;
    cout << setprecision(2) << "V: " << V << endl;
}

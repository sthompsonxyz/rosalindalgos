// biotest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <filesystem>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    cout << "Hello World!\n";

    map<pair<string, string>, double> blosMatrix{ 
        {{"ala","ala"}, +4.0 },
        {{"ala","arg"}, -1.0 }, 
        {{"ala","asn"}, -2.0 },
        {{"ala","asp"}, -2.0 },
        {{"ala","cys"}, +0.0 },};


    cout << blosMatrix[make_pair("ala", "ala")] << endl;

    //##
    map<string, double> aaOccurrance;
    map<string, double> ratioOccurrance;
    ifstream probsFile("C:\\Users\\sammysamsam\\source\\repos\\biotest1\\data\\aaProbsFile.txt", ifstream::in);
    string aaName;
    double pcOccurrance;
    while (probsFile >> aaName >> pcOccurrance) {
        //cout << aaName << " " << pcOccurrance << endl;
        aaOccurrance[aaName] = pcOccurrance;
        ratioOccurrance[aaName] = (pcOccurrance / 100.0);
    }


    double pcAccum = 0.0;
    auto aaOccEnd = aaOccurrance.end();
    for (auto it = aaOccurrance.begin(); it != aaOccEnd; ++it) {

        cout << it->first << " " << it->second << endl;
        pcAccum += it->second;

    }

    cout << pcAccum << endl;

    double rtAccum = 0.0;
    auto rtOccEnd = ratioOccurrance.end();
    for (auto it = ratioOccurrance.begin(); it != rtOccEnd; ++it) {

        cout << it->first << " " << it->second << endl;
        rtAccum += it->second;

    }
    cout << rtAccum << endl;

    probsFile.close();



    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

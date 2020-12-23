#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void prep_file(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <input filename> " << endl;
        exit(-1);
    }

    char *filename;
    ifstream in_file;

    filename = argv[1];
    in_file.open(filename);

    string text;
    while (getline(in_file, text))
    {
        jolts.push_back(stoi(text));
    }
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);
}
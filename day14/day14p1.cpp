#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

vector<string> masks;
vector<string> memory;
vector<string> input;

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

    while (!in_file.eof())
    {

        istringstream stream(text);

        getline(in_file, text);

        if (text == "mask")
        {
            getline(stream, text, '\n');
            masks.push_back(text.substr(2, text.size()));
        }
        else
        {

            memory.push_back(text);
        }
    }
}

void print_vect(vector<string> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);

    print_vect(memory);
}
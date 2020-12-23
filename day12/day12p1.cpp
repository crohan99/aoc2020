#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> actions;
int n, s, e, w, f;

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
        getline(in_file, text);
        actions.push_back(text);
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

    string heading;

    for (int i = 0; i < actions.size(); i++)
    {
        heading = actions[i].substr(0, 1);
        }
}
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

const int PREAMBLE = 25;
vector<long long> nums;
long long weak_num;
bool seen;

// open the file and dump the data into nums vector
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
        nums.push_back(stol(text));
    }
}

// useful for debugging
void print_vect()
{
    for (int i = PREAMBLE; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int check(int i)
{
    for (int j = i - PREAMBLE; j < i - 1; j++)
    {
        for (int k = i - PREAMBLE; k < i - 1; k++)
        {
            if (j != k && nums[j] + nums[k] == nums[i])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);

    // start at 26th number and for every number check if it is the sum of two of the last 25 nums
    for (int i = PREAMBLE; i < nums.size(); i++)
    {
        if (check(i) == 0)
        {
            cout << nums[i];
            return 0;
        }
    }
}
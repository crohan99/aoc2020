#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

int timestamp, range;
vector<string> buses;
vector<int> depart_times;

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
    getline(in_file, text);
    timestamp = stoi(text);

    getline(in_file, text);

    stringstream stream(text);

    while (getline(stream, text, ','))
    {
        buses.push_back(text);
        if (text == "x")
        {
            range++;
        }
    }
}

void print_vect(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int find_min(vector<int> nums)
{
    int min = 10000000;
    for (int z = 0; z < nums.size(); z++)
    {
        if (min > nums[z])
        {
            min = nums[z];
        }
    }
    return min;
}

int find_min_id(vector<int> nums)
{
    int min = 10000000, min_id;
    for (int z = 0; z < nums.size(); z++)
    {
        if (min > nums[z])
        {
            min = nums[z];
            min_id = z;
        }
    }
    return min_id;
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);

    int min, multiple;

    for (int i = 0; i < buses.size() - range; i++)
    {
    }
}
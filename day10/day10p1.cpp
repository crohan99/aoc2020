#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> jolts;
vector<int> cand_adapters;
int single_jolt, triple_jolt;

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

int find_min(vector<int> nums)
{
    int min = 1000;
    for (int z = 0; z < nums.size(); z++)
    {
        if (min > nums[z])
        {
            min = nums[z];
        }
    }
    return min;
}

void print_vect(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);

    int max = 0;
    for (int z = 0; z < jolts.size(); z++)
    {
        if (max < jolts[z])
        {
            max = jolts[z];
        }
    }

    int old_adapter;
    int adapter = 0;

    while (adapter < max)
    {
        for (int i = 0; i < jolts.size(); i++)
        {
            if (adapter + 1 == jolts[i] || adapter + 2 == jolts[i] || adapter + 3 == jolts[i])
            {
                cand_adapters.push_back(jolts[i]);
            }
        }

        old_adapter = adapter;
        adapter = find_min(cand_adapters);
        cand_adapters.clear();

        if (adapter - old_adapter == 3)
        {
            triple_jolt++;
        }
        if (adapter - old_adapter == 1)
        {
            single_jolt++;
        }
    }
    triple_jolt++;
    cout << single_jolt * triple_jolt;
}
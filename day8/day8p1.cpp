#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> operations;
vector<string> signs;
vector<int> nums;
vector<bool> flags;
int acc, iter;

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
        // first 3 chars are an operation, fill vector with operations
        operations.push_back(text.substr(0, 3));

        // next char is the sign of the number, fill vector with signs
        signs.push_back(text.substr(4, 1));

        // rest of chars are an operation parameter as an integer, fill vector with nums
        nums.push_back(stoi(text.substr(5, text.size())));

        // fill flags with false (not seen)
        flags.push_back(false);
    }
}

void print_vects()
{
    for (int i = 0; i < operations.size(); i++)
    {
        cout << operations[i] << '\t' << signs[i] << '\t' << nums[i] << '\t' << flags[i] << endl;
    }
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);

    iter = 0;
    acc = 0;

    while (flags[iter] != true)
    {
        flags[iter] = true;
        // acc operation
        if (operations[iter] == "acc")
        {
            // check sign, add or sub to acc
            if (signs[iter] == "+")
            {
                acc += nums[iter];
            }
            else if (signs[iter] == "-")
            {
                acc -= nums[iter];
            }
            else
            {
                cout << "sign error" << endl;
            }
            iter++;
        }
        // jmp operation
        else if (operations[iter] == "jmp")
        {
            // check sign, add or sub to iter
            if (signs[iter] == "+")
            {
                iter += nums[iter];
            }
            else if (signs[iter] == "-")
            {
                iter -= nums[iter];
            }
            else
            {
                cout << "sign error" << endl;
            }
        }
        // nop operation
        else
        {
            iter++;
        }
    }

    print_vects();

    cout << acc << endl;
}
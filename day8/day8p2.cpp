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
int i;
bool term = false;

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

bool check_term()
{
    int iter = 0;
    int acc = 0;
    while (iter < operations.size())
    {
        // keep track of seen operations
        if (flags[iter] == false)
        {
            flags[iter] = true;
        }
        else
        {
            return false;
        }

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

    iter = 0;
    acc = 0;

    // hit end of program, program terminates
    return true;
}

int main(int argc, char **argv)
{

    prep_file(argc, argv);

    while (!term && i < operations.size())
    {
        if (operations[i] == "jmp")
        {
            operations[i] = "nop";
            term = check_term();
            i++;
        }
        else if (operations[i] == "nop")
        {
            operations[i] = "jmp";
            term = check_term();
            i++;
        }
        else
        {
            i++;
        }
    }

    //print_vects();

    if (term)
    {
        cout << "Program terminates" << endl;
    }
    else
    {
        cout << "Program does not terminate" << endl;
    }

    //cout << acc << endl;
}
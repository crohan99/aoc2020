#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

char grid[9][9][2];
size_t n = sizeof(grid) / sizeof(grid[0][0][0]);

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

    char input;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            in_file.get(input);
            grid[i][j][1] = input;
        }
    }
}

void print_arr(char arr[9][9][2], size_t n)
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            //for (size_t k = 0; k < n; k++)
            //{
            cout << arr[i][j][1] << ' ';
            //}
        }
    }
}

void fill_arr(char arr[9][9][2], size_t n)
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            //for (size_t k = 0; k < 9; k++)
            //{
            arr[i][j][1] = '.';
            //}
        }
    }
}

int main(int argc, char **argv)
{
    fill_arr(grid, n);
    prep_file(argc, argv);
    print_arr(grid, n);
}
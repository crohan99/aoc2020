#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <input filename> " << endl;
        exit(-1);
    }

    char *filename;
    ifstream source_file;
    string in_line, target_string, min_string, max_string, password;
    int min, max, target_count = 0, valid_password_count = 0;
    char target;
    bool flag = false;

    // set filename as the input file
    filename = argv[1];

    // open the file
    source_file.open(filename);

    while (!source_file.eof())
    {
        getline(source_file, in_line);

        // string stream for the input, place in input
        stringstream check1(in_line);

        // split up input line into separate tokens
        getline(check1, min_string, '-');
        getline(check1, max_string, ' ');
        getline(check1, target_string, ':');
        getline(check1, password, '\n');

        // convert min_string and max_string into ints min and max
        min = stoi(min_string);
        max = stoi(max_string);

        // convert target_string into the target character
        target = target_string[0];

        for (int i = 1; i < password.length(); i++)
        {
            if (password[i] == target)
            {
                target_count++;
            }
        }
        if (target_count >= min && target_count <= max)
        {
            valid_password_count++;
        }
        target_count = 0;
    }
    cout << valid_password_count;
}
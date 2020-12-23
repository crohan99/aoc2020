#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
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

        cout << min;

        // convert target_string into the target character
        target = target_string[0];

        for (int i = 1; i < password.length(); i++)
        {
            // check if the target char is in the password and the location is either min or max
            if ((password[i] == target) && ((min == i) || (max == i)))
            {
                // check if we haven't seen a match
                if (flag == false)
                {
                    valid_password_count++;
                    flag = true;
                }
            }
        }
        flag = false;
    }
    cout << valid_password_count;
}
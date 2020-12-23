#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

// std::string text;
// std::ifstream ifs;
// ifs.open("data.txt", std::ifstream::in);

// std::vector<int> order;
// while (getline(ifs, text, ','))
// {
//     order.push_back(atoi(text.c_str()));
// }

vector<int> nums{0, 1, 5, 10, 3, 12, 19};

// finds duplicate number, return -1 if not found
int find_duplicate(vector<int> vect, int num)
{
    for (int i = vect.size() - 2; i >= 0; i--)
    {
        if (num == vect[i])
        {
            return i + 1;
        }
    }
    return -1;
}

void print_vect(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int main()
{

    int turn = nums.size() + 1,
        speak = 0,
        last,
        dupe;

    for (int i = 0; i <= 30000000 - 8; i++)
    {
        last = nums.back();

        cout << i << endl;

        dupe = find_duplicate(nums, last);

        if (dupe != -1)
        {
            nums.push_back((turn - 1) - dupe);
            //cout << turn << " " << dupe << endl;
        }
        else
        {
            nums.push_back(0);
        }
        turn++;
    }

    cout << nums.back();
}
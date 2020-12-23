#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

vector<string> player1;
vector<string> player2;

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

    string input;

    getline(in_file, input);

    for (int i = 0; i < 25; i++)
    {
        getline(in_file, input);
        player1.push_back(input);
    }

    getline(in_file, input);
    getline(in_file, input);

    for (int i = 0; i < 25; i++)
    {
        getline(in_file, input);
        player2.push_back(input);
    }
}

void print_vect(vector<string> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int find_winner()
{
    cout << "Player 1 plays: " << player1.front() << endl;
    cout << "Player 2 plays: " << player2.front() << endl;
    if (stoi(player1.front()) > stoi(player2.front()))
    {
        cout << "Player 1 wins!" << endl;
        return 1;
    }
    else if (stoi(player1.front()) < stoi(player2.front()))
    {
        cout << "Player 2 wins!" << endl;
        return 2;
    }
    else
    {
        return 0;
    }
}

void collect_cards(const int winner)
{
    string temp;
    if (winner == 1)
    {
        // put winning card on bottom of winning player's pile
        temp = player1.front();
        player1.erase(player1.begin());
        player1.push_back(temp);
        // put losing card on bottom of winning player's pile
        temp = player2.front();
        player2.erase(player2.begin());
        player1.push_back(temp);
    }
    else if (winner == 2)
    {
        temp = player2.front();
        player2.erase(player2.begin());
        player2.push_back(temp);
        temp = player1.front();
        player1.erase(player1.begin());
        player2.push_back(temp);
    }
    else
    {
        cout << "error occurred" << endl;
    }
}

int calculate_score(vector<string> player)
{
    int result = 0;
    for (int i = 0; i < player.size(); i++)
    {
        cout << player[i] << " * " << player.size() - i << endl;
        result += stoi(player[i]) * (player.size() - i);
    }
    return result;
}

void run_game()
{
    int i = 1;
    while (!player1.empty() && !player2.empty())
    {
        cout << "Round: " << i << endl;
        collect_cards(find_winner());
        i++;
    }

    if (player1.empty())
    {
        cout << calculate_score(player2);
    }
    else if (player2.empty())
    {
        cout << calculate_score(player1);
    }
    else
    {
        cout << "errror" << endl;
    }
}

int main(int argc, char **argv)
{
    prep_file(argc, argv);
    run_game();
}
/*

--- Part One ---

find the two entries that sum to 2020 and then multiply those two numbers together.

For example, suppose your expense report contained the following:

1721
979
366
299
675
1456

In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.

Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?

--- Part Two ---

The Elves in accounting are thankful for your help; one of them even offers you a starfish coin they had left over from a past vacation. They offer you a second one if you can find three numbers in your expense report that meet the same criteria.

Using the above example again, the three entries that sum to 2020 are 979, 366, and 675. Multiplying them together produces the answer, 241861950.

In your expense report, what is the product of the three entries that sum to 2020?

 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>
using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <input filename> " << endl;
    exit(-1);
  }

  // set filename as the input file
  char *filename = argv[1];

  // create a new ifstream
  ifstream source_file;

  // open the file
  source_file.open(filename);

  // storage for numbers
  list<int> numbers;

  // read line by line, storing each number in numbers
  int in;
  while (source_file >> in)
  {

    numbers.push_back(in);
  }

  list<int>::iterator i;
  list<int>::iterator j;
  list<int>::iterator k;

  for (i = numbers.begin(); i != numbers.end(); ++i)
  {

    for (j = numbers.begin(); j != numbers.end(); ++j)
    {

      for (k = numbers.begin(); k != numbers.end(); ++k)
      {

        if ((*i + *j + *k) == 2020)
        {

          cout << *i * *j * *k << endl;
        }
      }
    }
  }
}
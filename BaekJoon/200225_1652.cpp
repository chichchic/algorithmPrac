#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int roomSize;
  int vertical = 0, horizontal = 0;
  cin >> roomSize;
  int verCheck[103] = {};
  char temp;
  int horCheck;

  for (int i = 0; i < roomSize; i++)
  {
    horCheck = 0;
    for (int j = 0; j < roomSize; j++)
    {
      cin >> temp;
      if (temp == 'X')
      {
        if (horCheck >= 2)
          horizontal++;
        horCheck = 0;
        if (verCheck[j] >= 2)
          vertical++;
        verCheck[j] = 0;
      }
      else
      {
        horCheck++;
        verCheck[j]++;
      }
    }
    if (horCheck >= 2)
      horizontal++;
  }

  for (int i = 0; i < roomSize; i++)
  {
    if (verCheck[i] >= 2)
      vertical++;
  }
  cout << horizontal << ' ' << vertical;
  return 0;
}
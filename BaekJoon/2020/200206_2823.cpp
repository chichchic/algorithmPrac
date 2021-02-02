#include <iostream>

using namespace std;

bool map[12][12];
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
int main()
{
  // freopen("input.txt", "r", stdin);
  int r, c;
  char temp;
  bool noUturn = true;
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> temp;
      if (temp == '.')
        map[i][j] = true;
    }
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      int cnt = 0;
      if (map[i][j])
      {
        for (int k = 0; k < 4; k++)
        {
          int checkY = i + my[k];
          int checkX = j + mx[k];

          if (checkY >= 0 && checkY < r && checkX >= 0 && checkX < c)
          {
            if (map[checkY][checkX])
              cnt++;
          }
        }
        if (cnt < 2)
          noUturn = false;
      }
    }
  }
  if (noUturn)
    cout << 0;
  else
    cout << 1;
  return 0;
}
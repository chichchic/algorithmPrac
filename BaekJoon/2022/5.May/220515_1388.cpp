#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<char> prevLine(m, '.');
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char tile;
      cin >> tile;
      if (tile == '-')
      {
        if (j == 0)
        {
          answer++;
        }
        else if (prevLine[j - 1] != '-')
        {
          answer++;
        }
      }
      else
      {
        if (i == 0)
        {
          answer++;
        }
        else if (prevLine[j] != '|')
        {
          answer++;
        }
      }
      prevLine[j] = tile;
    }
  }
  cout << answer;
  return 0;
}
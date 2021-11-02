#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> vl;
typedef vector<vl> vvl;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int gap = m / 2;
  vvl level(n, vl(n));
  vvl answer(n, vl(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> level[i][j];
      level[i][j] *= -1;
    }
  }

  for (int i = gap; i < n - gap; i++)
  {
    for (int j = gap; j < n - gap; j++)
    {

      answer[i][j] = level[i - gap][j - gap];
      if (i - gap - 1 >= 0)
      {
        answer[i][j] -= level[i - gap - 1][j - gap];
      }
      if (j - gap - 1 >= 0)
      {
        answer[i][j] -= level[i - gap][j - gap - 1];
      }
      if (i - gap - 1 >= 0 && j - gap - 1 >= 0)
      {
        answer[i][j] += level[i - gap - 1][j - gap - 1];
      }
      if (i - m > 0)
      {
        answer[i][j] += answer[i - m][j];
      }
      if (j - m > 0)
      {
        answer[i][j] += answer[i][j - m];
      }
      if (i - m > 0 && j - m > 0)
      {
        answer[i][j] -= answer[i - m][j - m];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
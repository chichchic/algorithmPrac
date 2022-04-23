#include <iostream>
#include <vector>

using namespace std;
int n, m;

bool change(vector<vector<int>> &matrixA, int x, int y)
{
  for (int i = x; i < x + 3; i++)
  {
    if (i >= n)
    {
      return false;
    }
    for (int j = y; j < y + 3; j++)
    {
      if (j >= m)
      {
        return false;
      }
      matrixA[i][j] = (matrixA[i][j] == 0 ? 1 : 0);
    }
  }
  return true;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  vector<vector<int>> matrixA(n, vector<int>(m, 0));
  vector<vector<int>> matrixB(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%1d", &matrixA[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%1d", &matrixB[i][j]);
    }
  }

  int answer = 0;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = 0; j < m - 2; j++)
    {
      if (matrixA[i][j] != matrixB[i][j])
      {
        if (!change(matrixA, i, j))
        {
          cout << -1;
          return 0;
        }
        answer++;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrixA[i][j] != matrixB[i][j])
      {
        cout << -1;
        return 0;
      }
    }
  }
  cout << answer << '\n';
  return 0;
}
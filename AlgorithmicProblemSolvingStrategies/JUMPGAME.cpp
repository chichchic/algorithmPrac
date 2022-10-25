#include <iostream>
#include <vector>

using namespace std;

int mr[2] = {0, 1};
int mc[2] = {1, 0};

bool judge(int r, int c, vector<vector<bool>> &visited, vector<vector<int>> &matrix, const int n)
{
  if (r == n - 1 && c == n - 1)
  {
    return true;
  }
  for (int i = 0; i < 2; i++)
  {
    int nr = r + mr[i] * matrix[r][c];
    int nc = c + mc[i] * matrix[r][c];
    if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc])
    {
      continue;
    }
    visited[nr][nc] = true;
    if (judge(nr, nc, visited, matrix, n))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    int n;
    cin >> n;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> matrix[i][j];
      }
    }
    cout << (judge(0, 0, visited, matrix, n) ? "YES\n" : "NO\n");
  }

  return 0;
}
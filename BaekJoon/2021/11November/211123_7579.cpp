#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> task_info(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> task_info[i].second;
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> task_info[i].first;
  }
  sort(task_info.begin(), task_info.end());
  vector<vector<int>> matrix(101, vector<int>(10001));
  int answer = 1e9;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= 10000; j++)
    {
      if (i == 0)
      {
        matrix[i][j] = 0;
        continue;
      }
      if (task_info[i].first > j)
      {
        matrix[i][j] = matrix[i - 1][j];
      }
      else
      {
        matrix[i][j] = max(matrix[i - 1][j - task_info[i].first] + task_info[i].second, matrix[i - 1][j]);
      }
      if (matrix[i][j] >= m)
      {
        answer = min(answer, j);
      }
    }
  }
  cout << answer;
  return 0;
}
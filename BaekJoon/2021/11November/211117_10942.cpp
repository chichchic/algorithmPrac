#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }
  vector<vector<int>> answer(n, vector<int>(n));
  for (int j = 0; j < n; j++)
  {
    for (int start = 0; start + j < n; start++)
    {
      int end = start + j;
      if (start == end)
      {
        answer[start][end] = 1;
        continue;
      }
      if (start + 1 == end)
      {
        if (seq[start] == seq[end])
        {
          answer[start][end] = 1;
        }
        else
        {
          answer[start][end] = 0;
        }
        continue;
      }
      if (seq[start] == seq[end] && answer[start + 1][end - 1])
      {
        answer[start][end] = 1;
      }
      else
      {
        answer[start][end] = 0;
      }
    }
  }
  int m;
  cin >> m;
  int s, e;
  while (m--)
  {
    cin >> s >> e;
    cout << answer[s - 1][e - 1] << '\n';
  }

  return 0;
}
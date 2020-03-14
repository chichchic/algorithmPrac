#include <iostream>
#include <vector>

using namespace std;

int memo[403][403][403];

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, temp;
  cin >> n;
  int t_size = 0, b_size = 0;
  vector<int> top_box(n + 1);
  vector<int> bottom_box(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp != 0)
      top_box[t_size++] = temp;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp != 0)
      bottom_box[b_size++] = temp;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= min(t_size, i); j++)
    {
      for (int k = 1; k <= min(b_size, i); k++)
      {
        if (j > i - 1 && k > i - 1)
          memo[i][j][k] = memo[i - 1][j - 1][k - 1] + top_box[j - 1] * bottom_box[k - 1];
        else if (j > i - 1)
          memo[i][j][k] = max(memo[i - 1][j - 1][k], memo[i - 1][j - 1][k - 1] + top_box[j - 1] * bottom_box[k - 1]);
        else if (k > i - 1)
          memo[i][j][k] = max(memo[i - 1][j][k - 1], memo[i - 1][j - 1][k - 1] + top_box[j - 1] * bottom_box[k - 1]);
        else
          memo[i][j][k] = max(max(memo[i - 1][j - 1][k], memo[i - 1][j][k - 1]), memo[i - 1][j - 1][k - 1] + top_box[j - 1] * bottom_box[k - 1]);
      }
    }
  }
  cout << memo[n][t_size][b_size];
  return 0;
}
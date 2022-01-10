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
  vector<vector<bool>> covered(101, vector<bool>(101, false));
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    for (int x = a; x < a + 10; x++)
    {
      for (int y = b; y < b + 10; y++)
      {
        covered[x][y] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < 100; i++)
  {
    for (int j = 1; j < 100; j++)
    {
      if (covered[i][j])
      {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
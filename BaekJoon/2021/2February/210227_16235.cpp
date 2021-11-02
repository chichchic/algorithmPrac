//참고: https://lmcoa15.tistory.com/91

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct str
{
  int y;
  int x;
  int age;
  str(int y, int x, int age) : y(y), x(x), age(age){};
};

int main()
{

  freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  vector<vector<int>> fertilizer(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
  vector<int> tree[11][11];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      cin >> fertilizer[i][j];
      map[i][j] = 5;
    }

  int r, c, age;
  for (int i = 1; i <= m; i++)
  {
    cin >> r >> c >> age;
    tree[r][c].push_back(age);
  }

  while (k--)
  {
    vector<str> dead_tree;
    vector<str> growth_tree;

    for (int r = 1; r <= n; r++)
    {
      for (int c = 1; c <= n; c++)
      {
        if (tree[r][c].empty())
          continue;

        vector<int> vec;
        sort(tree[r][c].begin(), tree[r][c].end());
        for (int k = 0; k < tree[r][c].size(); k++)
        {
          age = tree[r][c][k];

          if (map[r][c] >= age)
          {
            map[r][c] -= age;
            vec.push_back(age + 1);

            if ((age + 1) % 5 == 0)
              growth_tree.push_back(str(r, c, age + 1));
          }
          else
          {
            dead_tree.push_back(str(r, c, age / 2));
          }
        }

        tree[r][c] = vec;
      }
    }

    for (int i = 0; i < dead_tree.size(); i++)
    {
      r = dead_tree[i].y;
      c = dead_tree[i].x;
      age = dead_tree[i].age;

      map[r][c] += age;
    }

    for (int i = 0; i < growth_tree.size(); i++)
    {

      r = growth_tree[i].y;
      c = growth_tree[i].x;

      for (int j = 0; j < 8; j++)
      {
        int ny = r + dy[j];
        int nx = c + dx[j];

        if (ny < 1 || ny > n || nx < 1 || nx > n)
          continue;

        tree[ny][nx].push_back(1);
      }
    }

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        map[i][j] += fertilizer[i][j];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      ans += tree[i][j].size();

  cout << ans << endl;
  return 0;
}
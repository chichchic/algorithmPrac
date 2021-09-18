#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int n, m;
vector<vector<int>> frog_preference(15, vector<int>(6));
vector<int> lotus(15, -1);
vector<vector<int>> log_info(100);
vector<int> answer;

bool rightArrange()
{
  for (int i = 0; i < n; i++)
  {
    if (lotus[i] < 0)
    {
      return false;
    }
  }
  for (int i = 0; i < m; ++i)
  {
    int a = log_info[i][0];
    int b = log_info[i][1];
    int t = log_info[i][2];
    int frogA = lotus[a];
    int frogB = lotus[b];
    if (frog_preference[frogA][t] != frog_preference[frogB][t])
    {
      return false;
    }
  }
  return true;
}

void arrangeFrog(int frog)
{
  if (frog == n)
  {
    if (rightArrange())
    {
      answer.assign(lotus.begin(), lotus.end());
    }
    return;
  }
  int a = frog_preference[frog][4];
  int b = frog_preference[frog][5];
  if (lotus[a] < 0)
  {
    lotus[a] = frog;
    arrangeFrog(frog + 1);
    lotus[a] = -1;
  }
  if (lotus[b] < 0)
  {
    lotus[b] = frog;
    arrangeFrog(frog + 1);
    lotus[b] = -1;
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      cin >> frog_preference[i][j];
    }
  }
  for (int i = 0; i < n; ++i)
  {
    int a, b;
    cin >> a >> b;
    frog_preference[i][4] = a - 1;
    frog_preference[i][5] = b - 1;
  }
  for (int i = 0; i < m; ++i)
  {
    int a, b, t;
    cin >> a >> b >> t;
    log_info[i] = {a - 1,
                   b - 1,
                   t - 1};
  }
  arrangeFrog(0);
  if (answer.size() == 0)
  {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i)
  {
    cout << answer[i] + 1 << ' ';
  }
  return 0;
}
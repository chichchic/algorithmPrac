#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;

int n, m, h;
int ans = 4;
bool isAnswer(vvb &bridge)
{
  vector<int> participant(n);
  for (int i = 0; i < n; i++)
  {
    participant[i] = i;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < h; j++)
    {
      int cur = participant[i];
      if (cur > 0 && bridge[cur - 1][j])
      {
        participant[i] -= 1;
      }
      else if (cur < n - 1 && bridge[cur][j])
      {
        participant[i] += 1;
      }
    }
    if (participant[i] != i)
    {
      return false;
    }
  }

  return true;
}

void drawBridge(vvb &bridge, int depth, int line_num, int bridge_num)
{
  if (depth >= ans)
  {
    return;
  }
  if (isAnswer(bridge))
  {
    ans = min(ans, depth);
    return;
  }
  for (int i = line_num; i < n - 1; i++)
  {
    for (int j = bridge_num; j < h; j++)
    {
      bridge_num = 0;
      if (bridge[i][j])
      {
        continue;
      }
      if (i > 0 && bridge[i - 1][j])
      {
        continue;
      }
      if (i < n - 2 && bridge[i + 1][j])
      {
        continue;
      }
      bridge[i][j] = true;
      int next_line = (j + 1) >= h ? i + 1 : i;
      int next_bridge = (j + 1) >= h ? 0 : j + 1;
      if (i < n - 1)
      {
        drawBridge(bridge, depth + 1, next_line, next_bridge);
      }
      bridge[i][j] = false;
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> h;

  vvb bridge(n - 1, vb(h, false));
  for (int i = 0; i < m; i++)
  {
    int line_num, bridge_num;
    cin >> bridge_num >> line_num;
    bridge[line_num - 1][bridge_num - 1] = true;
  }

  drawBridge(bridge, 0, 0, 0);

  if (ans > 3)
  {
    cout << -1;
  }
  else
  {
    cout << ans;
  }

  return 0;
}
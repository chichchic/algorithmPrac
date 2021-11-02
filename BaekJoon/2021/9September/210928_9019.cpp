#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int func_d(int n)
{
  return (2 * n) % 10000;
}

int func_s(int n)
{
  return (10000 + n - 1) % 10000;
}

int func_l(int n)
{
  return (n % 1000) * 10 + (n / 1000);
}

int func_r(int n)
{
  return (n % 10) * 1000 + (n / 10);
}

string find_answer(int n, int target)
{
  int (*fnP[4])(int) = {func_d, func_s, func_l, func_r};
  char command[4] = {'D', 'S', 'L', 'R'};
  queue<pair<string, int>> que;
  que.push({"", n});
  bool checked[10000] = {};
  checked[n] = true;
  while (!que.empty())
  {
    string cur_str = que.front().first;
    int cur_num = que.front().second;
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      if (i == 0 && cur_num == 0)
        continue;
      int nextNum = fnP[i](cur_num);
      if (nextNum == target)
      {
        return cur_str + command[i];
      }
      if (checked[nextNum])
        continue;
      checked[nextNum] = true;
      que.push({cur_str + command[i], nextNum});
    }
  }
  return "";
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    if (a == b)
    {
      cout << "\n";
      continue;
    }
    cout << find_answer(a, b) << '\n';
  }

  return 0;
}
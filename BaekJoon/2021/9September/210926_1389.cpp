#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int get_kb_number(int number, vector<vector<int>> &relation)
{
  vector<bool> visited(relation.size(), false);
  visited[number] = true;
  queue<int> que;
  que.push(number);
  que.push(-1);
  int output = 0;
  int step = 0;
  while (true)
  {
    int current = que.front();
    que.pop();
    if (que.empty())
    {
      break;
    }
    if (current == -1)
    {
      step++;
      que.push(-1);
      continue;
    }
    output += step;
    for (int i = 0; i < relation[current].size(); ++i)
    {
      int next = relation[current][i];
      if (visited[next])
        continue;
      visited[next] = true;
      que.push(next);
    }
  }
  return output;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int answer = 1;
  int n, m;
  cin >> n >> m;
  vector<int> kb_number(n + 1);
  vector<vector<int>> relation(n + 1);
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    relation[a].push_back(b);
    relation[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
    kb_number[i] = get_kb_number(i, relation);
    if (kb_number[i] < kb_number[answer])
      answer = i;
  }
  cout << answer;
  return 0;
}
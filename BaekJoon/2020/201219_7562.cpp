#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testCase;
  cin >> testCase;

  int m1[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int m2[8] = {1, -1, 2, -2, 2, -2, 1, -1};

  while (testCase--)
  {
    int size;
    cin >> size;
    int begin1, begin2;
    cin >> begin1 >> begin2;
    int dest1, dest2;
    cin >> dest1 >> dest2;
    queue<pii> que;
    int step = 0;
    bool visited[301][301] = {};
    visited[begin1][begin2] = true;
    que.push({begin1, begin2});
    que.push({-1, -1});
    while (true)
    {
      int cur1 = que.front().first, cur2 = que.front().second;
      que.pop();
      if (que.empty())
        break;
      if (cur1 == -1)
      {
        step++;
        que.push({-1, -1});
        continue;
      }
      if (cur1 == dest1 && cur2 == dest2)
        break;
      for (int i = 0; i < 8; i++)
      {
        int next1 = cur1 + m1[i];
        int next2 = cur2 + m2[i];
        if (next1 >= 0 && next2 >= 0 && next1 < size && next2 < size && !visited[next1][next2])
        {
          visited[next1][next2] = true;
          que.push({next1, next2});
        }
      }
    }
    cout << step << '\n';
  }
  return 0;
}
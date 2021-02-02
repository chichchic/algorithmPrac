#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct bridge
{
  int end;
  long long weight;
};

vector<vector<bridge>> bMap;
int n, m;
int sPoint, ePoint;
long long ans;

void bSearch(long long start, long long end)
{
  long long mid = (start + end) / 2; //최대 무게
  bool arrive = false;
  vector<bool> check(n, false);
  queue<int> que;
  que.push(sPoint);
  check[sPoint] = true;
  while (!que.empty())
  {
    int cur = que.front();
    que.pop();
    if (cur == ePoint)
    {
      arrive = true;
      break;
    }
    for (int i = 0; i < bMap[cur].size(); i++)
    {
      if (check[bMap[cur][i].end] || bMap[cur][i].weight < mid)
        continue;
      que.push(bMap[cur][i].end);
      check[bMap[cur][i].end] = true;
    }
  }

  if (arrive)
  {
    ans = mid;
    if (start >= end)
      return;
    bSearch(mid + 1, end);
  }
  else
  {
    if (start >= end)
      return;
    bSearch(start, mid - 1);
  }
}

int main()
{
  cin >> n >> m;
  bMap.resize(n + 1);
  int start, end;
  long long weight, min = 1000000003, max = 0;

  for (int i = 0; i < m; i++)
  {
    cin >> start >> end >> weight;

    bridge temp1 = {end, weight};
    bridge temp2 = {start, weight};
    if (weight < min)
      min = weight;
    if (weight > max)
      max = weight;
    bMap[start].push_back(temp1);
    bMap[end].push_back(temp2);
  }

  cin >> sPoint >> ePoint;

  bSearch(min, max);
  cout << ans;
  return 0;
}
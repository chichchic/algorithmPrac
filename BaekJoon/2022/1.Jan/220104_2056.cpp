#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> prevCnt(n+1, 0);
  vector<vector<int>> nextLink(n+1);
  vector<int> time(n+1);
  int answer = 0;
  vector<int> accTime(n+1, 0);
  for(int i = 1; i <= n; i++)
  {
    cin >> time[i];
    int cnt;
    cin >> cnt;
    for(int j = 0; j < cnt; j++)
    {
      int p;
      cin >> p;
      nextLink[p].push_back(i);
      prevCnt[i]++;
    }
  }
  queue<int> que;
  for(int i = 1; i <= n; i++)
  {
    if(prevCnt[i] == 0)
    {
      que.push(i);
    }
  }
  while(!que.empty())
  {
    int cur = que.front();
    que.pop();
    accTime[cur] += time[cur];
    answer = max(answer , accTime[cur]);
    for(int i = 0; i < nextLink[cur].size(); i++)
    {
      int next = nextLink[cur][i];
      prevCnt[next]--;
      accTime[next] = max(accTime[next], accTime[cur]);
      if(prevCnt[next] == 0)
      {
        que.push(next);
      }
    }
  }
  cout << answer;
  return 0;
}
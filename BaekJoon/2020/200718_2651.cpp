#include <iostream>
#include <vector>

#define infinity 1e10
using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long max_movement, center_count;
  cin >> max_movement >> center_count;
  vector<long long> gaps(center_count + 1);
  vector<long long> times(center_count + 2);
  pair<long long, long long> dp[center_count + 2];
  dp[0] = make_pair(0, -1);
  for (long long i = 0; i <= center_count; ++i)
  {
    cin >> gaps[i];
  }
  for (long long i = 1; i <= center_count; ++i)
  {
    cin >> times[i];
  }
  times[0] = 0;
  times[center_count + 1] = 0;
  for (long long i = 1; i < center_count + 2; i++)
  {
    long long energy = max_movement;
    dp[i] = make_pair(infinity, -1);
    for (long long j = i - 1; j >= 0; j--)
    {
      energy -= gaps[j];
      if (energy < 0)
        break;
      if (dp[i].first > dp[j].first + times[i])
      {
        dp[i].first = dp[j].first + times[i];
        dp[i].second = j;
      }
    }
  }
  cout << dp[center_count + 1].first << '\n';
  vector<long long> visited;
  long long prev = dp[center_count + 1].second;
  while (prev != 0)
  {
    visited.push_back(prev);
    prev = dp[prev].second;
  }
  cout << visited.size() << '\n';
  while (!visited.empty())
  {
    cout << visited.back() << ' ';
    visited.pop_back();
  }
  return 0;
}
/*
//NOTE: 재채점 결과 런타임 에러로 변경
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int maxLen, centerNum;
  cin >> maxLen >> centerNum;
  vector<int> centerDis(centerNum + 4, 0), centerTime(centerNum + 4, 0);
  int dpFirst[104] = {};  //beforecenter
  int dpSecond[104] = {}; //time
  for (int i = 1; i <= centerNum + 1; i++)
  {
    cin >> centerDis[i];
  }
  for (int i = 1; i <= centerNum; i++)
  {
    cin >> centerTime[i];
  }
  for (int i = 1; i <= centerNum + 1; i++)
  {
    int runLen = centerDis[i];
    int candiTime = 2147483647;
    int cur;
    for (int j = i - 1; j >= 0; j--)
    {
      if (runLen > maxLen)
        break;
      int curCandiTime = centerTime[i] + dpSecond[j];
      if (curCandiTime < candiTime)
      {
        candiTime = curCandiTime;
        cur = j;
      }
      runLen += centerDis[j];
    }
    dpFirst[i] = cur;
    dpSecond[i] = candiTime;
  }

  vector<int> ans;
  int curpoint = dpFirst[centerNum + 1];
  while (curpoint > 0)
  {
    ans.push_back(curpoint);
    curpoint = dpFirst[curpoint];
  }

  printf("%d\n", dpSecond[centerNum + 1]);
  printf("%lu\n", ans.size());
  for (int i = ans.size() - 1; i >= 0; i--)
    printf("%d ", ans[i]);
  return 0;
}
*/

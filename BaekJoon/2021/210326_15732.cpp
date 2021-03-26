#include <iostream>
#include <vector>

using namespace std;

struct ruleInfo
{
  int start, end, interval;
};

long long AcornCounter(int limit, ruleInfo rules[], const int k)
{
  long long acorncount = 0;
  for (int i = 0; i < k; i++)
  {
    if (limit < rules[i].start)
    {
      continue;
    }
    int endBox = min(rules[i].end, limit);
    int count = (endBox - rules[i].start) / rules[i].interval + 1;
    acorncount += count;
  }
  return acorncount;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, d;
  cin >> n >> k >> d;
  ruleInfo rules[10000];

  for (int i = 0; i < k; i++)
  {
    cin >> rules[i].start >> rules[i].end >> rules[i].interval;
  }

  int start = 0, end = 1000000;
  while (start + 1 < end)
  {
    int mid = (start + end) / 2;
    long long count = AcornCounter(mid, rules, k);
    if (count >= d)
    {
      end = mid;
    }
    else
    {
      start = mid;
    }
  }
  cout << end;
  return 0;
}
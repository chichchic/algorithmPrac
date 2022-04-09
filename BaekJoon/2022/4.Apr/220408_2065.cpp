#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long m, t, n;
  cin >> m >> t >> n;
  vector<long long> timeTable(n);
  queue<pair<long long, long long>> lQue;
  queue<pair<long long, long long>> rQue;
  vector<pair<long long, long long>> lTable;
  vector<pair<long long, long long>> rTable;
  for (long long i = 0; i < n; i++)
  {
    long long arriveTime;
    string location;
    cin >> arriveTime >> location;
    if (location == "left")
    {
      lTable.push_back({arriveTime, i});
    }
    else if (location == "right")
    {
      rTable.push_back({arriveTime, i});
    }
  }
  sort(lTable.begin(), lTable.end());
  sort(rTable.begin(), rTable.end());
  long long curTime = 0;
  bool boatLeft = true;
  long long ldx = 0, rdx = 0;
  while (ldx < lTable.size() || rdx < rTable.size())
  {
    long long board = 0;
    if (boatLeft)
    {
      while (board < m && ldx < lTable.size() && curTime >= lTable[ldx].first)
      {
        timeTable[lTable[ldx].second] = curTime + t;
        ldx++;
        board++;
      }
    }
    else
    {
      while (board < m && rdx < rTable.size() && curTime >= rTable[rdx].first)
      {
        timeTable[rTable[rdx].second] = curTime + t;
        rdx++;
        board++;
      }
    }
    if (board > 0)
    {
      curTime += t;
      boatLeft = !boatLeft;
      continue;
    }
    if (boatLeft && rdx < rTable.size() && curTime >= rTable[rdx].first)
    {
      curTime += t;
      boatLeft = false;
      continue;
    }
    else if (!boatLeft && ldx < lTable.size() && curTime >= lTable[ldx].first)
    {
      curTime += t;
      boatLeft = true;
      continue;
    }
    curTime++;
  }
  for (int i = 0; i < n; i++)
  {
    cout << timeTable[i] << '\n';
  }
  return 0;
}
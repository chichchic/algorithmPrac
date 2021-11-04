#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
pair<ll, ll> teleport1[3];
pair<ll, ll> teleport2[3];
bool used[3] = {};
ll xs, ys, xe, ye;
ll answer = 1e12;

ll getDistance(ll x1, ll x2, ll y1, ll y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}

void moveTeleport(ll curX, ll curY, ll curTime)
{
  ll candi = curTime + getDistance(curX, xe, curY, ye);
  answer = min(answer, candi);
  for (int i = 0; i < 3; i++)
  {
    if (used[i])
    {
      continue;
    }
    used[i] = true;
    auto t1 = teleport1[i];
    auto t2 = teleport2[i];
    ll t1Dist = curTime + getDistance(t1.first, curX, t1.second, curY) + 10;
    ll t2Dist = curTime + getDistance(t2.first, curX, t2.second, curY) + 10;
    moveTeleport(t2.first, t2.second, t1Dist);
    moveTeleport(t1.first, t1.second, t2Dist);
    used[i] = false;
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> xs >> ys >> xe >> ye;
  for (int i = 0; i < 3; i++)
  {
    cin >> teleport1[i].first >> teleport1[i].second;
    cin >> teleport2[i].first >> teleport2[i].second;
  }
  moveTeleport(xs, ys, 0);
  cout << answer;
  return 0;
}
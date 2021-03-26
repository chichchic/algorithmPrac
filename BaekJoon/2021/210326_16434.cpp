#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

struct roomInfo
{
  int t, a, h;
};

bool simulate(roomInfo rooms[], const int n, long long atk, long long maxHP)
{
  long long curHP = maxHP;
  for (int i = 0; i < n; i++)
  {
    if (rooms[i].t == 1)
    {
      long long atkCount = ceil(rooms[i].h / (double)atk);
      curHP -= (atkCount - 1) * rooms[i].a;
      if (curHP <= 0)
      {
        return false;
      }
    }
    else
    {
      curHP = min(maxHP, curHP + rooms[i].h);
      atk += rooms[i].a;
    }
  }
  return true;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, atk;
  cin >> n >> atk;
  roomInfo rooms[123457];
  for (int i = 0; i < n; i++)
  {
    cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;
  }

  long long ans = LLONG_MAX;
  long long s = 0, e = LLONG_MAX;
  while (s + 1 < e)
  {
    long long mid = (s + e) / 2;
    if (simulate(rooms, n, atk, mid))
    {
      ans = min(mid, ans);
      e = mid;
    }
    else
    {
      s = mid;
    }
  }

  cout << ans;
  return 0;
}
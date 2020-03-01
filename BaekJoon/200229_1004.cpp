#include <iostream>
#include <vector>

using namespace std;

struct point
{
  int x, y;
};

struct planetPoint
{
  int x, y, r;
};

bool inside(point p, planetPoint pl)
{
  return (p.x - pl.x) * (p.x - pl.x) + (p.y - pl.y) * (p.y - pl.y) < pl.r * pl.r;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int t, n;
  cin >> t;
  while (t--)
  {
    int ans = 0;
    point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    cin >> n;
    vector<planetPoint> planet(n);
    vector<bool> inPlanet(n, false);
    for (int i = 0; i < n; i++)
    {
      cin >> planet[i].x >> planet[i].y >> planet[i].r;
      if (inside(start, planet[i]))
      {
        ans++;
        inPlanet[i] = true;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (inside(end, planet[i]))
      {
        if (inPlanet[i])
          ans--;
        else
          ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
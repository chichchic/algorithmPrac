#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
int ans = 999999999;
int n, m;

void calcCityChickenDist(const vvi &chicken_dist, vi &city_dist, int depth, int startIdx)
{
  if (depth == m)
  {
    int sum = 0;
    for (int i = 0; i < city_dist.size(); i++)
    {
      sum += city_dist[i];
    }
    ans = min(ans, sum);
    return;
  }
  for (int i = startIdx; i < chicken_dist.size() - m + depth + 1; i++)
  {
    vi temp_dist;
    for (int j = 0; j < city_dist.size(); j++)
    {
      temp_dist.push_back(min(city_dist[j], chicken_dist[i][j]));
    }
    calcCityChickenDist(chicken_dist, temp_dist, depth + 1, i + 1);
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vvi city_map(n, vi(n));
  vpii chicken_store;
  vvi chicken_dist;
  vpii home;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> city_map[i][j];
      if (city_map[i][j] == 1)
      {
        home.push_back(make_pair(i, j));
      }
      else if (city_map[i][j] == 2)
      {
        chicken_store.push_back(make_pair(i, j));
      }
    }
  }

  for (int i = 0; i < chicken_store.size(); i++)
  {
    int chickenX = chicken_store[i].first;
    int chickenY = chicken_store[i].second;
    vi cur_chicken_dist;
    for (int j = 0; j < home.size(); j++)
    {
      int x = abs(chickenX - home[j].first);
      int y = abs(chickenY - home[j].second);
      cur_chicken_dist.push_back(x + y);
    }
    chicken_dist.push_back(cur_chicken_dist);
  }
  vi city_dist(home.size(), 999999999);
  calcCityChickenDist(chicken_dist, city_dist, 0, 0);

  cout << ans;

  return 0;
}
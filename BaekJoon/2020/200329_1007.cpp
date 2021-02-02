#include <iostream>
#include <cmath>

using namespace std;

long long sx, sy;
int memo[20][2], n;

long long my_min(long long a, long long b)
{
  return (a == 9223372036854775807) ? b : (a > b) ? b : a;
}

long long func(int left, int index, long long x, long long y)
{
  if (left == 0)
    return (sx - x - x) * (sx - x - x) + (sy - y - y) * (sy - y - y);

  long long ans = 9223372036854775807;
  for (; index < n; index++)
  {
    ans = my_min(ans, func(left - 1, index + 1, x + memo[index][0], y + memo[index][1]));
  }
  return ans;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--)
  {
    sx = 0;
    sy = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf(" %d %d", &memo[i][0], &memo[i][1]);
      sx += memo[i][0];
      sy += memo[i][1];
    }
    printf("%.8lf\n", sqrt((double)func(n / 2, 0, 0, 0)));
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long getDepth(long long num, long long k)
{
  long long depth = 0;
  if (k == 1)
  {
    return num;
  }
  while (num > 1)
  {
    num = (num + k - 2) / k;
    depth++;
  }
  return depth;
}

long long getDistance(long long k)
{
  long long x, y;
  cin >> x >> y;
  long long x_depth = getDepth(x, k);
  long long y_depth = getDepth(y, k);
  long long answer = 0;
  if (k == 1)
  {
    return abs(x_depth - y_depth);
  }
  while (x_depth != y_depth)
  {
    if (x_depth > y_depth)
    {
      x_depth--;
      x = (x + k - 2) / k;
      answer++;
    }
    else
    {
      y_depth--;
      y = (y + k - 2) / k;
      answer++;
    }
  }
  while (x != y)
  {
    x = (x + k - 2) / k;
    y = (y + k - 2) / k;
    answer += 2;
  }
  return answer;
}

int main()
{
  // freopen("../input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, q;
  cin >> n >> k >> q;

  while (q--)
  {
    cout << getDistance(k) << '\n';
  }

  return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int ans = 987654321;
bool find = false;
void nature(int n, int cnt)
{
  if (cnt > ans)
    return;
  if (n == 0)
  {
    if (ans > cnt)
      ans = cnt;
    return;
  }
  int max = (int)floor(sqrt(n));
  for (int i = max; i >= 1; i--)
  {
    int cntUp = n / (i * i);
    nature(n - (i * i) * cntUp, cnt + cntUp);
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  nature(n, 0);
  cout << ans;
  return 0;
}
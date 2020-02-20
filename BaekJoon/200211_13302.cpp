#include <iostream>

#define INF 987654321

using namespace std;

int n, m;
int dp[101][101]; // [cupon][day]
bool rest[101];

int dsp(int cupon, int day)
{
  if (day > n)
    return 0;
  if (dp[cupon][day] != INF)
    return dp[cupon][day];
  if (rest[day])
    return dp[cupon][day] = dsp(cupon, day + 1);
  dp[cupon][day] = min(dp[cupon][day], dsp(cupon, day + 1) + 10000);
  dp[cupon][day] = min(dp[cupon][day], dsp(cupon + 1, day + 3) + 25000);
  dp[cupon][day] = min(dp[cupon][day], dsp(cupon + 2, day + 5) + 37000);

  if (cupon >= 3)
    dp[cupon][day] = min(dp[cupon][day], dsp(cupon - 3, day + 1));
  return dp[cupon][day];
}

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> n >> m;
  int temp;
  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    rest[temp] = true;
  }
  fill(&dp[0][0], &dp[0][0] + 101 * 101, INF);
  cout << dsp(0, 1);
  return 0;
}
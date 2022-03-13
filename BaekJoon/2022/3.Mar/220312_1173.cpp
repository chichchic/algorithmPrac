#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, m, M, T, R;
  cin >> N >> m >> M >> T >> R;
  int answer = 0;
  int exersieTime = 0;
  int initPulse = m;
  bool flag = false;
  while (exersieTime < N)
  {
    if (m + T <= M)
    {
      exersieTime++;
      m += T;
      flag = false;
    }
    else if (m - R > initPulse)
    {
      m -= R;
      flag = false;
    }
    else
    {
      if (flag)
      {
        cout << -1;
        return 0;
      }
      m = initPulse;
      flag = true;
    }
    answer++;
  }
  cout << answer;
  return 0;
}
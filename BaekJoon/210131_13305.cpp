#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long cityNum;
  cin >> cityNum;
  vector<long long> gasStation(cityNum);
  vector<long long> loadLens(cityNum - 1);
  for (long long i = 0; i < cityNum - 1; i++)
  {
    cin >> loadLens[i];
  }
  for (long long i = 0; i < cityNum; i++)
  {
    cin >> gasStation[i];
  }

  long long curGas = gasStation[0];
  long long ans = 0;
  for (long long i = 0; i < cityNum - 1; i++)
  {
    if (curGas > gasStation[i])
    {
      curGas = gasStation[i];
    }
    ans += curGas * loadLens[i];
  }
  cout << ans;
  return 0;
}
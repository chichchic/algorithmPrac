#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n;
  cin >> n;
  vector<long long> cross(n, 0);
  vector<long long> left(n, 0);
  vector<long long> right(n, 0);

  for (long long i = 0; i < n; i++)
    cin >> cross[i];
  for (long long i = 1; i < n; i++)
  {
    cin >> left[i];
    left[i] += left[i - 1];
  }
  for (long long i = 0; i < n - 1; i++)
  {
    cin >> right[i];
  }
  long long ans = left[n - 1] + cross[n - 1] + right[n - 1];
  long long croNum = n - 1;
  for (long long i = n - 2; i >= 0; i--)
  {
    right[i] += right[i + 1];
    long long candi = left[i] + cross[i] + right[i];
    if (ans >= candi)
    {
      croNum = i;
      ans = candi;
    }
  }
  cout << croNum + 1 << ' ' << ans;
  return 0;
}
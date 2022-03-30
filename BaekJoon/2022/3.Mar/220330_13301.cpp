#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  if (n == 1)
  {
    cout << 4;
    return 0;
  }
  vector<long long> size;
  size.push_back(0);
  size.push_back(1);
  size.push_back(1);
  for (long long i = 3; i <= n; i++)
  {
    size.push_back(size[i - 1] + size[i - 2]);
  }
  cout << (size[n] + size[n] + size[n - 1]) * 2;
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n;
  cin >> n;
  long long total = 0;
  vector<long long> store(n);
  for (long long i = 0; i < n; i++)
  {
    scanf(" %lld", &store[i]);
    total += store[i];
  }
  long long idx;
  for (idx = 0; idx < n; idx++)
  {
    if (total - store[idx] == store[idx])
      break;
  }

  for (long long i = 0; i < n; i++)
  {
    if (i == idx)
      continue;
    cout << store[i] << ' ';
  }
  cout << store[idx];

  return 0;
}
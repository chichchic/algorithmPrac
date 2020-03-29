#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> pll;

int main()
{
  freopen("input.txt", "r", stdin);
  long long t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    vector<pll> input(n);
    for (int i = 0; i < n; i++)
    {
      cin >> input[i].first >> input[i].second;
    }
    sort(input.begin(), input.end());
  }
  return 0;
}
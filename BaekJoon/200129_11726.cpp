#include <iostream>

using namespace std;

long long store[1003] = {1, 2};

long long dp(int n)
{
  if (store[n] != 0)
    return store[n];
  store[n] = dp(n - 1) + dp(n - 2);
  return store[n];
}

int main()
{
  int n;
  cin >> n;
  cout << dp(n - 1);
  // for문으로 짜볼것!!!! (bottom-up)
  return 0;
}
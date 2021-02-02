#include <iostream>

using namespace std;

long long store[1003] = {1, 2};

long long dp(int n)
{
  if (store[n] != 0)
    return store[n];
  store[n] = (dp(n - 1) + dp(n - 2)) % 10007;
  return store[n];
}

int main()
{
  int n;
  cin >> n;
  cout << dp(n - 1);
  // for(int i = 2; i < n; i++)
  // {
  //   store[i] = (store[i-1] + store[i-2]) %10007;
  // }
  cout << store[n - 1];
  return 0;
}
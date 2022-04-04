#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long testCase;
  cin >> testCase;
  vector<long long> counter1(100001);
  vector<long long> counter2(100001);
  vector<long long> counter3(100001);
  counter1[0] = 0;
  counter2[0] = 0;
  counter3[0] = 0;
  counter1[1] = 1;
  counter2[1] = 0;
  counter3[1] = 0;
  counter1[2] = 0;
  counter2[2] = 1;
  counter3[2] = 0;
  counter1[3] = 1;
  counter2[3] = 1;
  counter3[3] = 1;
  for (long long i = 4; i <= 100000; i++)
  {
    counter1[i] = (counter2[i - 1] + counter3[i - 1]) % MOD;
    counter2[i] = (counter1[i - 2] + counter3[i - 2]) % MOD;
    counter3[i] = (counter1[i - 3] + counter2[i - 3]) % MOD;
  }
  while (testCase--)
  {
    long long n;
    cin >> n;
    cout << (counter1[n] + counter2[n] + counter3[n]) % MOD << '\n';
  }

  return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  unordered_map<int, int> hash;

  for (int i = 0; i < n; i++)
  {
    int numerator, denominator;
    cin >> numerator >> denominator;
    numerator = denominator - numerator;
    for (int j = 2; j * j <= numerator; j++)
    {
      if (numerator % j == 0)
      {
        if (hash.find(j) == hash.end())
        {
          hash[j] = 0;
        }
        hash[j]++;
        numerator /= j;
        j--;
      }
    }
    if (numerator > 1)
    {
      if (hash.find(numerator) == hash.end())
      {
        hash[numerator] = 0;
      }
      hash[numerator]++;
    }

    for (int j = 2; j * j <= denominator; j++)
    {
      if (denominator % j == 0)
      {
        if (hash.find(j) == hash.end())
        {
          hash[j] = 0;
        }
        hash[j]--;
        denominator /= j;
        j--;
      }
    }
    if (denominator > 1)
    {
      if (hash.find(denominator) == hash.end())
      {
        hash[denominator] = 0;
      }
      hash[denominator]--;
    }
  }

  long long ansNumerator = 1;
  long long ansDenominator = 1;

  for (auto iter = hash.begin(); iter != hash.end(); iter++)
  {
    int cur = iter->first;
    int cnt = iter->second;
    if (cnt > 0)
    {
      for (int j = 0; j < cnt; j++)
      {
        ansNumerator *= cur;
        ansNumerator %= MOD;
      }
    }
    else if (cnt < 0)
    {
      cnt *= -1;
      for (int j = 0; j < cnt; j++)
      {
        ansDenominator *= cur;
        ansDenominator %= MOD;
      }
    }
  }

  cout << ansNumerator << ' ' << ansDenominator;

  return 0;
}
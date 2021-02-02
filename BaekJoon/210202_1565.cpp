#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
  long long tmp, n;
  if (a < b)
  {
    tmp = a;
    a = b;
    b = tmp;
  }

  while (b != 0)
  {
    n = a % b;
    a = b;
    b = n;
  }

  return a;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long sizeD, sizeM;
  cin >> sizeD >> sizeM;

  vector<long long> d(sizeD);
  for (long long i = 0; i < sizeD; i++)
  {
    cin >> d[i];
  }

  long long x;
  long long y;
  cin >> x;
  vector<long long> m;
  m.push_back(x);
  for (long long i = 1; i < sizeM; i++)
  {
    cin >> y;
    m.push_back(y);
    x = gcd(x, y);
  }
  set<long long> divisors;
  for (long long i = 1; i <= (double)sqrt(x); i++)
  {
    if (x % i == 0)
    {
      divisors.insert(i);
      divisors.insert(x / i);
    }
  }
  for (auto iter = divisors.begin(); iter != divisors.end();)
  {
    bool isAnswer = true;
    for (long long i = 0; isAnswer && i < sizeD; i++)
    {
      long long curVal = d[i];
      if (*iter % curVal != 0)
      {
        isAnswer = false;
        break;
      }
    }
    if (!isAnswer)
    {
      iter = divisors.erase(iter);
      continue;
    }
    iter++;
  }

  cout << divisors.size();
  return 0;
}
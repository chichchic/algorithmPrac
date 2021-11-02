#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_RANGE = 1e7;

vector<bool> isPrime(MAX_RANGE, true);

bool checkPrime(int number)
{
  for (int i = 2; i <= pow(number, 0.5); i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }
  return true;
}

void findAmagingPrime(int currentNum, const int targetDepth, int currentDepth)
{
  if (targetDepth == currentDepth)
  {
    cout << currentNum << '\n';
    return;
  }
  for (int i = 1; i <= 9; i++)
  {
    int nextNum = currentNum * 10 + i;
    if (currentDepth + 1 < 8)
    {
      if (!isPrime[nextNum])
      {
        continue;
      }
    }
    else if (!checkPrime(nextNum))
    {
      continue;
    }
    findAmagingPrime(nextNum, targetDepth, currentDepth + 1);
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i <= 3164; i++)
  {
    int j = 2;
    while (j * i < MAX_RANGE)
    {
      isPrime[j * i] = false;
      j++;
    }
  }
  int n;
  cin >> n;
  vector<int> initNumber = {
      2,
      3,
      5,
      7,
  };

  if (n == 1)
  {
    for (int init : initNumber)
    {
      cout << init << '\n';
    }
    return 0;
  }
  for (int init : initNumber)
  {
    findAmagingPrime(init, n, 1);
  }
  return 0;
}
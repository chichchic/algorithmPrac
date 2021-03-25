#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void swap(string &numbers, int f, int s)
{
  char temp = numbers[f];
  numbers[f] = numbers[s];
  numbers[s] = temp;
}

int changeStrToInt(string &numbers, int len)
{
  int output = 0;
  for (int i = 0; i < len; i++)
  {
    output *= 10;
    output += numbers[i] - '0';
  }
  return output;
}

void permutation(string &numbers, vector<bool> &isPrime, int depth, int &ans, int len)
{

  if (depth >= len)
  {
    int curNumber = changeStrToInt(numbers, len);
    if (isPrime[curNumber])
    {
      ans++;
      isPrime[curNumber] = false;
    }
    return;
  }
  for (int i = depth; i < numbers.length(); i++)
  {
    swap(numbers, depth, i);
    permutation(numbers, isPrime, depth + 1, ans, len);
    swap(numbers, i, depth);
  }
}

int solution(string numbers)
{
  int answer = 0;
  sort(numbers.begin(), numbers.begin());
  int maxNumber = 9999999;

  vector<bool> isPrime(maxNumber + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;

  int primeIndex = 2;
  while (primeIndex <= maxNumber)
  {
    if (!isPrime[primeIndex])
    {
      primeIndex++;
      continue;
    }

    for (int i = 2; primeIndex * i <= maxNumber; i++)
    {
      isPrime[primeIndex * i] = false;
    }
    primeIndex++;
  }
  for (int i = 1; i <= numbers.length(); i++)
    permutation(numbers, isPrime, 0, answer, i);

  return answer;
}
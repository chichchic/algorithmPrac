#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(char inequal[], vector<int> num, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (inequal[i] == '<')
    {
      if (num[i] >= num[i + 1])
        return false;
    }
    else if (inequal[i] == '>')
    {
      if (num[i] <= num[i + 1])
        return false;
    }
  }
  return true;
}
/*
  TODO:

    next_permutation과 prev_permutation 구현해보기
*/
int main()
{
  int k;
  char inequal[10];
  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> inequal[i];
  vector<int> big;
  vector<int> small;
  for (int i = 9; i >= 9 - k; i--)
  {
    big.push_back(i);
  }
  for (int i = 0; i <= k; i++)
  {
    small.push_back(i);
  }

  do
  {
    if (check(inequal, big, k))
    {
      for (int i = 0; i <= k; i++)
        cout << big[i];
      cout << '\n';
      break;
    }
  } while (prev_permutation(big.begin(), big.end()));

  do
  {
    if (check(inequal, small, k))
    {
      for (int i = 0; i <= k; i++)
        cout << small[i];
      cout << '\n';
      break;
    }
  } while (next_permutation(small.begin(), small.end()));

  return 0;
}
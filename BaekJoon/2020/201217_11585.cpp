#include <iostream>
#include <vector>

using namespace std;

int gcd(int big, int small)
{
  while (!small)
  {
    int remainder = big % small;
    big = small;
    small = remainder;
  }
  return small;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<char> rullet(n * 2 - 1);
  for (int i = 0; i < n; i++)
  {
    cin >> rullet[i];
    if (i != n - 1)
      rullet[n + i] = rullet[i];
  }
  vector<char> word(n);
  for (int i = 0; i < n; i++)
  {
    cin >> word[i];
  }
  vector<int> fail(n, 0);
  for (int i = 1, j = 0; i < n; i++)
  {
    while (j > 0 && word[i] != word[j])
      j = fail[j - 1];
    if (word[i] == word[j])
      fail[i] = ++j;
  }
  int count = 0;
  for (int i = 0, j = 0; i < n * 2 - 1; i++)
  {
    while (j > 0 && rullet[i] != word[j])
      j = fail[j - 1];
    if (rullet[i] == word[j])
    {
      if (j == n - 1)
      {
        count++;
        j = fail[j];
      }
      else
      {
        j++;
      }
    }
  }
  if (n == count)
    cout << "1/1";
  else
  {
    int gcdNum = gcd(n, count);
    cout << count / gcdNum << '/' << n / gcdNum;
  }
  return 0;
}
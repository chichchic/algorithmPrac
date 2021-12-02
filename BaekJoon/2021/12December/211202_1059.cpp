#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int L;
  cin >> L;
  vector<int> seq(L);

  for (int i = 0; i < L; i++)
  {
    cin >> seq[i];
  }
  seq.push_back(0);

  int n;
  cin >> n;
  int s, e;
  bool b = true;

  sort(seq.begin(), seq.end());
  for (int i = 1; i < L + 1; i++)
  {
    if (n == seq[i])
      b = false;
    else if (n < seq[i])
    {
      s = seq[i - 1] + 1;
      e = seq[i] - 1;
      break;
    }
  }

  if (b)
    cout << (n - s) * (e - n + 1) + (e - n);
  else
    cout << 0;

  return 0;
}
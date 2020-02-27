#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
int main()
{
  // freopen("input.txt", "r", stdin);
  int len, candiNum;
  cin >> len;
  vector<int> ori(len);
  vector<int> rev(len);
  vector<int> candidate(len);
  vector<vi> ans;
  for (int i = 0; i < len; i++)
  {
    cin >> ori[i];
    rev[len - i - 1] = (ori[i] + 2) % 4;
    if (rev[len - i - 1] == 0)
      rev[len - i - 1] = 4;
  }
  cin >> candiNum;
  while (candiNum--)
  {
    for (int i = 0; i < len; i++)
      cin >> candidate[i];
    int i = 0;
    for (; i < len; i++)
    {
      bool oriCorrect = true;
      bool revCorrect = true;
      int j = 0;
      for (; j < len - i; j++)
      {
        if (ori[i + j] != candidate[j])
          oriCorrect = false;
        if (rev[i + j] != candidate[j])
          revCorrect = false;
        if (!oriCorrect && !revCorrect)
          break;
      }
      if (oriCorrect)
      {
        for (int i = 0; i < len - j; i++)
        {
          if (ori[i] != candidate[j + i])
          {
            oriCorrect = false;
            break;
          }
        }
      }
      if (revCorrect)
      {
        for (int i = 0; i < len - j; i++)
        {
          if (rev[i] != candidate[j + i])
          {
            revCorrect = false;
            break;
          }
        }
      }
      if (oriCorrect || revCorrect)
      {
        ans.push_back(candidate);
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < len; j++)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
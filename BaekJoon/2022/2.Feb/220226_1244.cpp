#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int swc, stc;
  cin >> swc;
  vector<int> sws(swc + 1);
  for (int i = 1; i <= swc; i++)
  {
    cin >> sws[i];
  }
  cin >> stc;
  int sex, num;
  for (int i = 0; i < stc; i++)
  {
    cin >> sex >> num;
    if (sex == 1)
    {
      for (int j = 1; j * num <= swc; j++)
      {
        sws[j * num] = (sws[j * num] + 1) % 2;
      }
    }
    if (sex == 2)
    {
      for (int j = 0; num - j > 0 && num + j <= swc; j++)
      {
        if (sws[num - j] == sws[num + j])
        {
          sws[num - j] = sws[num + j] = (sws[num + j] + 1) % 2;
          continue;
        }
        break;
      }
    }
  }
  for (int i = 0;; i++)
  {
    for (int j = 1; j <= 20; j++)
    {
      if (i * 20 + j > swc)
      {
        return 0;
      }
      cout << sws[i * 20 + j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
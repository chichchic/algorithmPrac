#include <iostream>

using namespace std;

int answer[4] = {};
void recursive(int scores[6][3], int tc, int p, int q)
{
  if (p == 6)
  {
    answer[tc] = 1;
    return;
  }
  if (q == 6)
  {
    recursive(scores, tc, p + 1, p + 2);
    return;
  }
  scores[p][0]--;
  scores[q][2]--;
  if (scores[p][0] >= 0 && scores[q][2] >= 0)
  {
    recursive(scores, tc, p, q + 1);
  }
  scores[p][0]++;
  scores[q][2]++;

  scores[p][1]--;
  scores[q][1]--;
  if (scores[p][1] >= 0 && scores[q][1] >= 0)
  {
    recursive(scores, tc, p, q + 1);
  }
  scores[p][1]++;
  scores[q][1]++;

  scores[p][2]--;
  scores[q][0]--;
  if (scores[p][2] >= 0 && scores[q][0] >= 0)
  {
    recursive(scores, tc, p, q + 1);
  }
  scores[p][2]++;
  scores[q][0]++;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 4; i++)
  {
    int scores[6][3];
    int total = 0;
    for (int j = 0; j < 6; j++)
    {
      int sum = 0;
      for (int k = 0; k < 3; k++)
      {
        cin >> scores[j][k];
        sum += scores[j][k];
        total += scores[j][k];
      }
      if (sum != 5)
      {
        answer[i] = -1;
      }
    }
    if (total != 30)
    {
      answer[i] = -1;
    }
    if (answer[i] == -1)
    {
      answer[i] = 0;
      continue;
    }
    recursive(scores, i, 0, 1);
  }
  for (int i = 0; i < 4; i++)
  {
    cout << answer[i] << ' ';
  }
  return 0;
}
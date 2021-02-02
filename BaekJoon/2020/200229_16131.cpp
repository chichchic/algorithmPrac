#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, a, b, m;
int hong, jo;
int totalHaapy = 0, dbdHappy = 0, longHaapy = 0;

void hjHappy()
{
  // cout << "h: " << hong << " jo: " << jo << '\n';
  if (abs(hong - jo) <= b)
  {
    totalHaapy++;
    dbdHappy++;
  }
  else
  {
    dbdHappy = 0;
  }
  if (longHaapy < dbdHappy)
    longHaapy = dbdHappy;
}

void changeRoom(int i, int j, vector<int> &score)
{
  // i = good room, j = bad room
  score[i] += 2;
  score[j] -= 2;
  int temp = score[i];
  score[i] = score[j];
  score[j] = temp;
  if (i == hong)
    hong = j;
  else if (j == hong)
    hong = i;
  if (i == jo)
    jo = j;
  else if (j == jo)
    jo = i;
}

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> n >> a >> b >> m;
  hong = 1;
  jo = a;
  hjHappy();
  m--;
  while (m--)
  {
    vector<int> score(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> score[i];
    for (int i = 1; i <= n; i++)
    {
      int temp;
      cin >> temp;
      score[i] -= temp;
    }
    for (int i = 1; i < n; i++)
    {
      if (score[i] >= 0 && score[i + 1] >= 0 && score[i + 1] - score[i] >= 2)
      {
        changeRoom(i, i + 1, score);
      }
      else if (score[i + 1] >= 0 && score[i] < 0)
      {
        changeRoom(i, i + 1, score);
      }
      else if (score[i] < 0 && score[i + 1] < 0 && score[i + 1] - score[i] >= 4)
      {
        changeRoom(i, i + 1, score);
      }
    }
    hjHappy();
  }
  cout << totalHaapy << ' ' << longHaapy;
  return 0;
}
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

struct f_unit
{
  int x;
  int y;
  int day;
};

int t, w, h;
int space[1003][1003]; // -1: wall, 1: fire
int fireDay[1003][1003];
long long minDay = 1234567890, maxDay = 0;
long long ans;
bool impossible;
pair<int, int> start_point;

int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};

void escape()
{
  bool check[1003][1003] = {};
  bool exit = false;
  queue<f_unit> que;
  f_unit people = {start_point.first, start_point.second, 0};
  que.push(people);
  check[people.x][people.y] = true;

  while (!que.empty())
  {
    f_unit cur = que.front();
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      f_unit next = {cur.x + mx[i],
                     cur.y + my[i],
                     cur.day + 1};
      if (next.x >= 0 && next.y >= 0 && next.x < h && next.y < w)
      {
        if (!check[next.x][next.y] && fireDay[next.x][next.y] != -1 && fireDay[next.x][next.y] > next.day)
        {
          que.push(next);
          check[next.x][next.y] = true;
        }
      }
      else
      {
        if (ans > next.day)
          ans = next.day;
        exit = true;
      }
    }
  }
  if (exit)
    cout << ans << '\n';
  else
    cout << "IMPOSSIBLE\n";
}

int main()
{
  char input_char;
  t = 1;
  while (t--)
  {
    cin >> w >> h;
    queue<f_unit> que;
    bool check[1003][1003] = {};
    impossible = true;
    ans = 1234567890;
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {

        cin >> input_char;
        if (input_char == 'J')
        {
          start_point = make_pair(i, j);
        }
        if (input_char == '#')
        {
          space[i][j] = -1;
          fireDay[i][j] = -1;
          check[i][j] = true;
        }
        else if (input_char == 'F')
        {
          space[i][j] = 1;
          fireDay[i][j] = 0;
          f_unit temp = {i, j, 0};
          que.push(temp);
          check[i][j] = true;
        }
        else
        {
          space[i][j] = 0;
          fireDay[i][j] = 2000000000;
        }
      }
    }
    while (!que.empty())
    {
      f_unit cur = que.front();
      que.pop();
      for (int i = 0; i < 4; i++)
      {
        f_unit next = {cur.x + mx[i], cur.y + my[i], cur.day + 1};
        if (next.x >= 0 && next.x < h && next.y >= 0 && next.y < w && !check[next.x][next.y] && space[next.x][next.y] != -1)
        {
          fireDay[next.x][next.y] = next.day;
          if (minDay > next.day)
            minDay = next.day;
          if (maxDay < next.day)
            maxDay = next.day;
          que.push(next);
          check[next.x][next.y] = true;
        }
      }
    }
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        cout << fireDay[i][j] << ' ';
      }
      cout << '\n';
    }
    escape();
  }
}
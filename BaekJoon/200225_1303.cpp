#include <iostream>
#include <queue>

using namespace std;

char war[101][101];
bool checkW[101][101] = {};
bool checkB[101][101] = {};
int warSizeX, warSizeY;
int wPower = 0, bPower = 0;
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

struct point
{
  int first, second;
  point(int a, int b) : first(a), second(b){};
};

int main()
{
  // freopen("input.txt", "r", stdin);
  cin >> warSizeX >> warSizeY;
  for (int i = 0; i < warSizeY; i++)
  {
    for (int j = 0; j < warSizeX; j++)
    {
      cin >> war[i][j];
    }
  }
  queue<point> queW;
  queue<point> queB;
  for (int i = 0; i < warSizeY; i++)
  {
    for (int j = 0; j < warSizeX; j++)
    {
      if (war[i][j] == 'W' && !checkW[i][j])
      {
        queW.push(point(i, j));
        checkW[i][j] = true;

        int wSize = 0;
        while (!queW.empty())
        {
          wSize++;
          int y = queW.front().first;
          int x = queW.front().second;
          queW.pop();

          for (int i = 0; i < 4; i++)
          {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (nx >= 0 && nx < warSizeX && ny >= 0 && ny < warSizeY)
            {
              if (!checkW[ny][nx] && war[ny][nx] == 'W')
              {
                queW.push(point(ny, nx));
                checkW[ny][nx] = true;
              }
            }
          }
        }
        wPower += (wSize * wSize);
      }
    }
  }
  for (int i = 0; i < warSizeY; i++)
  {
    for (int j = 0; j < warSizeX; j++)
    {
      if (war[i][j] == 'B' && !checkB[i][j])
      {
        queB.push(point(i, j));
        checkB[i][j] = true;

        int bSize = 0;
        while (!queB.empty())
        {
          bSize++;
          int y = queB.front().first;
          int x = queB.front().second;
          queB.pop();

          for (int i = 0; i < 4; i++)
          {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (nx >= 0 && nx < warSizeX && ny >= 0 && ny < warSizeY)
            {
              if (!checkB[ny][nx] && war[ny][nx] == 'B')
              {
                queB.push(point(ny, nx));
                checkB[ny][nx] = true;
              }
            }
          }
        }
        bPower += (bSize * bSize);
      }
    }
  }
  cout << wPower << ' ' << bPower;
  return 0;
}
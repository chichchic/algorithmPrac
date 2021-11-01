#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int l;
int startX = 0;
int startY = 0;
int pieceCount[6] = {};
vector<pair<int, int>> piecePos[6];
vector<vector<int>> paper;
vector<bool> insertedStatus(6, false);
bool insertPiece(int num, int x, int y, int count)
{
  if (num > 5)
  {
    return false;
  }
  if (x >= l)
  {
    return false;
  }
  bool canInsert = true;
  int idx = 0;
  for (; idx < piecePos[num].size(); idx++)
  {
    int nextX = x + piecePos[num][idx].first;
    int nextY = y + piecePos[num][idx].second;
    if (nextX < 0 || nextY < 0 || nextX >= l || nextY >= l || paper[nextX][nextY] != 0)
    {
      canInsert = false;
      break;
    }
    if (startX == nextX && startY == nextY)
    {
      while (true)
      {
        startY++;
        if (startY >= l)
        {
          startX++;
          startY = 0;
        }
        if (startX >= l || paper[startX][startY] == 0)
        {
          break;
        }
      }
    }
    paper[nextX][nextY] = num;
  }

  int nextCount = count;

  if (canInsert)
  {
    insertedStatus[num] = true;
    int nextNum = 1;
    nextCount += pieceCount[num];
    while (nextNum == num || (nextNum <= 5 && insertedStatus[nextNum]))
    {
      nextNum++;
    }
    if (num <= 5 && insertPiece(nextNum, startX, startY, nextCount))
    {
      return true;
    }
    if (nextNum > 5)
    {
      if (nextCount == l * l)
      {
        return true;
      }
    }
  }
  insertedStatus[num] = false;
  idx--;
  for (; idx >= 0; idx--)
  {
    int nextX = x + piecePos[num][idx].first;
    int nextY = y + piecePos[num][idx].second;
    if (startX > nextX || (startX == nextX && startY > nextY))
    {
      startX = nextX;
      startY = nextY;
    }
    paper[nextX][nextY] = 0;
  }
  int nextNum = num + 1;
  while (nextNum <= 5 && insertedStatus[nextNum])
  {
    nextNum++;
  }
  if (nextNum <= 5 && insertPiece(nextNum, startX, startY, count))
  {
    return true;
  }
  return false;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> l;
  paper.resize(l, vector<int>(l, 0));
  for (int num = 1; num <= 5; num++)
  {
    int n, m;
    cin >> n >> m;
    int sx = -1, sy = -1;
    char c;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> c;
        if (c == '.')
        {
          continue;
        }
        pieceCount[num]++;
        if (sx == -1)
        {
          sx = i;
          sy = j;
          piecePos[num].push_back({0, 0});
          continue;
        }
        piecePos[num].push_back({i - sx, j - sy});
      }
    }
  }
  vector<bool> insertedStatus(6, false);
  if (insertPiece(1, startX, startY, 0))
  {
    for (auto line : paper)
    {
      for (auto c : line)
      {
        cout << c;
      }
      cout << '\n';
    }
  }
  else
  {
    cout << "gg";
  }
  return 0;
}
//NOTE: ref - https://yabmoons.tistory.com/117
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<char>> seatTable(5, vector<char>(5));

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

bool checkMemberLinking(vector<pair<int, int>> pickedMember)
{
  queue<pair<int, int>> que;
  que.push(pickedMember[0]);
  vector<bool> visited(pickedMember.size(), false);
  visited[0] = true;
  int visitedCnt = 1;
  while (!que.empty())
  {
    int curX = que.front().first;
    int curY = que.front().second;
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int nextX = curX + mx[i];
      int nextY = curY + my[i];
      for (int j = 0; j < pickedMember.size(); j++)
      {
        if (visited[j])
        {
          continue;
        }
        if (pickedMember[j].first == nextX && pickedMember[j].second == nextY)
        {
          visited[j] = true;
          que.push(pickedMember[j]);
          visitedCnt++;
        }
      }
    }
  }
  return visitedCnt == 7;
}

int answer = 0;
void checkMember(vector<pair<int, int>> &pickedMember)
{
  int ydsCnt = 0;
  for (auto pos : pickedMember)
  {
    if (seatTable[pos.first][pos.second] == 'S')
    {
      ydsCnt++;
    }
  }
  if (ydsCnt >= 4)
  {
    if (checkMemberLinking(pickedMember))
    {
      answer++;
    }
  }
  return;
}

void pickMember(int cnt, int x, int y, vector<pair<int, int>> &pickedMember)
{
  if (cnt == 7)
  {
    checkMember(pickedMember);
    return;
  }
  if (x >= 5)
  {
    return;
  }
  if (y >= 5)
  {
    pickMember(cnt, x + 1, 0, pickedMember);
    return;
  }
  pickedMember.push_back({x, y});
  pickMember(cnt + 1, x, y + 1, pickedMember);
  pickedMember.pop_back();
  pickMember(cnt, x, y + 1, pickedMember);
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> seatTable[i][j];
    }
  }
  vector<pair<int, int>> pickedMember;
  pickMember(0, 0, 0, pickedMember);
  cout << answer;
  return 0;
}
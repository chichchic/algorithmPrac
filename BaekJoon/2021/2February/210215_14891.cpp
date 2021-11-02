#include <iostream>
#include <utility>

using namespace std;

struct gear
{
  int gearInfo[8];
  int leftIdx;
  int rightIdx;
  int twelveDirIdx;
};

void rotateGear(gear &g, int dir)
{
  dir *= -1;
  g.leftIdx = (8 + g.leftIdx + dir) % 8;
  g.rightIdx = (8 + g.rightIdx + dir) % 8;
  g.twelveDirIdx = (8 + g.twelveDirIdx + dir) % 8;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  gear g[4];

  for (int i = 0; i < 4; i++)
  {
    string gearStr;
    cin >> gearStr;
    for (int j = 0; j < 8; j++)
    {
      g[i].gearInfo[j] = gearStr[j] - '0';
    }
    g[i].leftIdx = 6;
    g[i].rightIdx = 2;
    g[i].twelveDirIdx = 0;
  }

  int k;
  cin >> k;

  for (int i = 0; i < k; i++)
  {
    int rotateNum, rotateDir;
    cin >> rotateNum >> rotateDir;
    rotateNum -= 1;
    int rotateQue[4] = {};
    rotateQue[rotateNum] = rotateDir;

    int leftGearNum = rotateNum - 1;
    int leftRotateDir = rotateDir * -1;
    while (leftGearNum >= 0)
    {
      int curGearLeftIdx = g[leftGearNum + 1].leftIdx;
      int leftGearRightIdx = g[leftGearNum].rightIdx;
      if (g[leftGearNum + 1].gearInfo[curGearLeftIdx] == g[leftGearNum].gearInfo[leftGearRightIdx])
      {
        break;
      }
      rotateQue[leftGearNum] = leftRotateDir;
      leftGearNum--;
      leftRotateDir *= -1;
    }

    int rightGearNum = rotateNum + 1;
    int rightRotateDir = rotateDir * -1;
    while (rightGearNum < 4)
    {
      int curGearRightIdx = g[rightGearNum - 1].rightIdx;
      int rightGearLeftIdx = g[rightGearNum].leftIdx;
      if (g[rightGearNum - 1].gearInfo[curGearRightIdx] == g[rightGearNum].gearInfo[rightGearLeftIdx])
      {
        break;
      }
      rotateQue[rightGearNum] = rightRotateDir;

      rightGearNum++;
      rightRotateDir *= -1;
    }
    for (int j = 0; j < 4; j++)
    {
      if (rotateQue[j] == 0)
      {
        continue;
      }
      rotateGear(g[j], rotateQue[j]);
    }
  }

  int ans = 0;
  for (int i = 0; i < 4; i++)
  {
    int twelveDirIdx = g[i].twelveDirIdx;
    if (g[i].gearInfo[twelveDirIdx])
    {
      ans += (1 << i);
    }
  }

  cout << ans;

  return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main()
{
  //freopen("input.txt", "r", stdin);
  int s;
  string n;
  cin >> s >> n;
  int height = 2 * s + 3;
  int width = s + 2;
  vc numBlockRow(width, ' ');
  vvc numBlock(height, numBlockRow);
  vector<vvc> numCandi(10, numBlock);
  vector<vc> ans(height, vc());
  bool numBar[10][7] = {
      {true, true, true, true, true, true, false},     //0
      {false, true, true, false, false, false, false}, //1
      {true, true, false, true, true, false, true},    //2
      {true, true, true, true, false, false, true},    //3
      {false, true, true, false, false, true, true},   //4
      {true, false, true, true, false, true, true},    //5
      {true, false, true, true, true, true, true},     //6
      {true, true, true, false, false, false, false},  //7
      {true, true, true, true, true, true, true},      //8
      {true, true, true, true, false, true, true}      //9
  };
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (numBar[i][j])
      {
        if (j == 0)
        {
          for (int k = 1; k < width - 1; k++)
          {
            numCandi[i][0][k] = '-';
          }
        }
        else if (j == 1)
        {
          for (int k = 1; k < height / 2; k++)
          {
            numCandi[i][k][width - 1] = '|';
          }
        }
        else if (j == 2)
        {
          for (int k = height / 2 + 1; k < height - 1; k++)
          {
            numCandi[i][k][width - 1] = '|';
          }
        }
        else if (j == 3)
        {
          for (int k = 1; k < width - 1; k++)
          {
            numCandi[i][height - 1][k] = '-';
          }
        }
        else if (j == 4)
        {
          for (int k = height / 2 + 1; k < height - 1; k++)
          {
            numCandi[i][k][0] = '|';
          }
        }
        else if (j == 5)
        {
          for (int k = 1; k < height / 2; k++)
          {
            numCandi[i][k][0] = '|';
          }
        }
        else if (j == 6)
        {
          for (int k = 1; k < width - 1; k++)
          {
            numCandi[i][height / 2][k] = '-';
          }
        }
      }
    }
  }

  for (int i = 0; i < n.length(); i++)
  {
    for (int j = 0; j < height; j++)
    {
      for (int k = 0; k < width; k++)
      {
        ans[j].push_back(numCandi[n[i] - '0'][j][k]);
      }
      ans[j].push_back(' ');
    }
  }
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j];
    }
    cout << '\n';
  }
  return 0;
}
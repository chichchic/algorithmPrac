#include <iostream>

using namespace std;

int store[1003][3] = {};
int price[1003][3];
int ans = 123456789;

int dp(int n, int color)
{
  if(store[n][color] == 0)
  {
    if(color == 0)
     store[n][color] = min(dp(n-1, 1), dp(n-1, 2)) + price[n][color];
    else if(color == 1)
     store[n][color] = min(dp(n-1, 0), dp(n-1, 2)) + price[n][color];
    else if(color == 2)
     store[n][color] = min(dp(n-1, 1), dp(n-1, 0)) + price[n][color];
  }
  return store[n][color];
}

int main()
{
  int n;
  cin >> n;
  // 재귀문으로 짜볼것!!!! (top-down)

   for (int i = 0; i < n; i++)
   {
     for (int j = 0; j < 3; j++)
     {
       cin >> price[i][j];
     }
   }
   for (int j = 0; j < 3; j++)
     store[0][j] = price[0][j];

  // for (int i = 1; i < n; i++)
  // {
  //   for (int j = 0; j < 3; j++)
  //   {
  //     int sVal;
  //     if (j == 0)
  //       sVal = min(store[i - 1][1], store[i - 1][2]);
  //     else if (j == 1)
  //       sVal = min(store[i - 1][2], store[i - 1][0]);
  //     else if (j == 2)
  //       sVal = min(store[i - 1][1], store[i - 1][0]);
  //     store[i][j] = price[i][j] + sVal;
  //     if (i == n - 1)
  //       ans = min(ans, store[i][j]);
  //   }
  // }
  cout << min(dp(n-1, 0), min(dp(n-1,1), dp(n-1,2)));
  return 0;
}
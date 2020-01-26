#include <iostream>
#include <queue>

using namespace std;

struct pieces
{
  int w;
  int h;
  int step;
  int k;
};

int k, w, h;
bool board[201][201];
bool check[201][201][30];
int ans = -1;
queue<pieces> que;
int main()
{
  cin >> k >> w >> h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> board[i][j];
    }
  }
  check[0][0][k] = true;
  pieces temp = {0, 0, 0, k};
  que.push(temp);

  while (!que.empty())
  {
    pieces cur = que.front();
    que.pop();

    if (cur.w == w - 1 && cur.h == h - 1)
    {
      cout << cur.step << '\n';
      return 0;
    }

    if (cur.k > 0)
    {
      if (cur.w - 2 >= 0 && cur.h - 1 >= 0)
      {
        pieces temp = {cur.w - 2, cur.h - 1, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w - 1 >= 0 && cur.h - 2 >= 0)
      {
        pieces temp = {cur.w - 1, cur.h - 2, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w - 2 >= 0 && cur.h + 1 < h)
      {
        pieces temp = {cur.w - 2, cur.h + 1, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w - 1 >= 0 && cur.h + 2 < h)
      {
        pieces temp = {cur.w - 1, cur.h + 2, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w + 2 < w && cur.h - 1 >= 0)
      {
        pieces temp = {cur.w + 2, cur.h - 1, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w + 1 < w && cur.h - 2 >= 0)
      {
        pieces temp = {cur.w + 1, cur.h - 2, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w + 2 < w && cur.h + 1 < h)
      {
        pieces temp = {cur.w + 2, cur.h + 1, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
      if (cur.w + 1 < w && cur.h + 2 < h)
      {
        pieces temp = {cur.w + 1, cur.h + 2, cur.step + 1, cur.k - 1};
        if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
        {
          que.push(temp);
          check[temp.h][temp.w][temp.k] = true;
        }
      }
    }
    if (cur.h + 1 < h)
    {
      pieces temp = {cur.w, cur.h + 1, cur.step + 1, cur.k};
      if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
      {
        que.push(temp);
        check[temp.h][temp.w][temp.k] = true;
      }
    }
    if (cur.w + 1 < w)
    {
      pieces temp = {cur.w + 1, cur.h, cur.step + 1, cur.k};
      if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
      {
        que.push(temp);
        check[temp.h][temp.w][temp.k] = true;
      }
    }
    if (cur.w - 1 >= 0)
    {
      pieces temp = {cur.w - 1, cur.h, cur.step + 1, cur.k};
      if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
      {
        que.push(temp);
        check[temp.h][temp.w][temp.k] = true;
      }
    }
    if (cur.h - 1 >= 0)
    {
      pieces temp = {cur.w, cur.h - 1, cur.step + 1, cur.k};
      if (!board[temp.h][temp.w] && !check[temp.h][temp.w][temp.k])
      {
        que.push(temp);
        check[temp.h][temp.w][temp.k] = true;
      }
    }
  }
  cout << -1;
  return 0;
}
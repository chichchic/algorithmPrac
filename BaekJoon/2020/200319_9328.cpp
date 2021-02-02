#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef vector<bool> vb;

struct point
{
  int row, col;
  point(int r, int c) : row(r), col(c) {}
};

void entrance(queue<point> &que, vb &key, point cur, char input, int &doorCnt, int &document)
{
  if (input == '*')
    return;
  if (input >= 'a' && input <= 'z')
  {
    key[input - 'a'] = true;
  }
  else if (input >= 'A' && input <= 'Z')
  {
    doorCnt++;
  }
  if (input == '$')
  {
    document++;
  }
  que.push(cur);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int mrow[4] = {0, 0, 1, -1};
    int mcol[4] = {1, -1, 0, 0};
    int ans = 0;
    int row, col;
    cin >> row >> col;
    vector<string> floor_map(row);
    vb temp(col, false);
    vector<vb> check(row, temp);
    queue<point> que;
    vb key(26, false);
    string key_input;
    int doorCnt = 0;
    int document = 0;

    for (int i = 0; i < row; i++)
    {
      cin >> floor_map[i];
    }
    cin >> key_input;
    if (key_input != "0")
    {
      for (int i = 0; i < key_input.length(); i++)
        key[key_input[i] - 'a'] = true;
    }

    for (int i = 0; i < col; i++)
    {
      check[0][i] = true;
      check[row - 1][i] = true;
      entrance(que, key, point(0, i), floor_map[0][i], doorCnt, document);
      entrance(que, key, point(row - 1, i), floor_map[row - 1][i], doorCnt, document);
    }
    for (int i = 1; i < row - 1; i++)
    {
      check[i][0] = true;
      check[i][col - 1] = true;
      entrance(que, key, point(i, 0), floor_map[i][0], doorCnt, document);
      entrance(que, key, point(i, col - 1), floor_map[i][col - 1], doorCnt, document);
    }
    int doors = 0;
    while (!que.empty() && doors <= doorCnt + 3)
    {
      point cur = que.front();
      // cout << cur.row << ' ' << cur.col << '\n';
      // cout << doors << ' ' << doorCnt << '\n';
      que.pop();
      char cf = floor_map[cur.row][cur.col];
      if (cf >= 'A' && cf <= 'Z')
      {
        // cout << cf << ' ' << cur.row << ' ' << cur.col << ' ' << doors << ' ' << doorCnt << '\n';
        if (key[cf - 'A'])
        {
          doorCnt--;
          floor_map[cur.row][cur.col] = '.';
        }
        else
        {
          doors++;
          que.push(cur);
          check[cur.row][cur.col] = false;
          continue;
        }
      }
      doors = 0;
      for (int i = 0; i < 4; i++)
      {
        point next(cur.row + mrow[i], cur.col + mcol[i]);
        if (next.row >= 0 && next.row < row && next.col >= 0 && next.col < col && !check[next.row][next.col])
        {
          // cout << next.row << ' ' << next.col << '\n';
          char nf = floor_map[next.row][next.col];
          check[next.row][next.col] = true;
          if (nf == '*')
          {
            continue;
          }
          else if (nf >= 'a' && nf <= 'z')
          {
            key[nf - 'a'] = true;
          }
          else if (nf == '$')
          {
            document++;
          }
          else if (nf >= 'A' && nf <= 'Z')
          {
            doorCnt++;
          }
          que.push(next);
        }
      }
    }
    cout << document << '\n';
  }
  return 0;
}
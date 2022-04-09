#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int h = n * 2 - 1;
  // 최상단
  for (int i = 0; i < n; i++)
  {
    cout << '*';
  }
  for (int i = 0; i < h - 2; i++)
  {
    cout << ' ';
  }
  for (int i = 0; i < n; i++)
  {
    cout << '*';
  }
  cout << '\n';
  // 상단
  for (int i = 1; i <= n - 2; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << ' ';
    }
    cout << '*';
    for (int j = 0; j < n - 2; j++)
    {
      cout << ' ';
    }
    cout << '*';
    for (int j = 0; j < h - 2 * (i + 1); j++)
    {
      cout << ' ';
    }
    cout << '*';
    for (int j = 0; j < n - 2; j++)
    {
      cout << ' ';
    }
    cout << '*';
    cout << '\n';
  }
  // 중간
  for (int i = 0; i < n - 1; i++)
  {
    cout << ' ';
  }
  cout << '*';
  for (int j = 0; j < n - 2; j++)
  {
    cout << ' ';
  }
  cout << '*';
  for (int j = 0; j < n - 2; j++)
  {
    cout << ' ';
  }
  cout << '*';
  cout << '\n';
  // 하단
  for (int i = n - 2; i >= 1; i--)
  {
    for (int j = 0; j < i; j++)
    {
      cout << ' ';
    }
    cout << '*';
    for (int j = 0; j < n - 2; j++)
    {
      cout << ' ';
    }
    cout << '*';
    for (int j = 0; j < h - 2 * (i + 1); j++)
    {
      cout << ' ';
    }
    cout << '*';
    for (int j = 0; j < n - 2; j++)
    {
      cout << ' ';
    }
    cout << '*';
    cout << '\n';
  }
  // 최하단
  for (int i = 0; i < n; i++)
  {
    cout << '*';
  }
  for (int i = 0; i < h - 2; i++)
  {
    cout << ' ';
  }
  for (int i = 0; i < n; i++)
  {
    cout << '*';
  }
  return 0;
}
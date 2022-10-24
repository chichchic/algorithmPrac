#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a += b * (10 ^ K)
void add(vector<int> &a, vector<int> &b, int k)
{
  a.resize(max(a.size(), b.size() + k));
  for (int i = 0; i < b.size(); i++)
  {
    a[i + k] += b[i];
  }
}

// a의 크기 >= b의 크기 일 때, a -= b;
void sub(vector<int> &a, vector<int> &b)
{
  for (int i = 0; i < b.size(); i++)
  {
    a[i] -= b[i];
  }
}

// a * b;
vector<int> multiply(vector<int> &a, vector<int> &b)
{
  vector<int> ret(a.size() + b.size() - 1, 0);
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      ret[i + j] += a[i] * b[j];
    }
  }
  return ret;
}

vector<int> karatsuba(vector<int> &a, vector<int> &b)
{
  if (a.size() < b.size())
  {
    return karatsuba(b, a);
  }
  if (a.size() == 0 || b.size() == 0)
  {
    return vector<int>();
  }
  if (a.size() <= 50)
  {
    return multiply(a, b);
  }
  int half = a.size() / 2;
  vector<int> a0(a.begin(), a.begin() + half);
  vector<int> a1(a.begin() + half, a.end());
  vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
  vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

  vector<int> z2 = karatsuba(a1, b1);
  vector<int> z0 = karatsuba(a0, b0);
  add(a0, a1, 0);
  add(b0, b1, 0);
  vector<int> z1 = karatsuba(a0, b0);
  sub(z1, z0);
  sub(z1, z2);

  vector<int> ret(a.size() + b.size() - 1, 0);
  add(ret, z0, 0);
  add(ret, z1, half);
  add(ret, z2, half * 2);
  return ret;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    vector<int> members, fans;
    string genders;
    cin >> genders;
    for (int i = 0; i < genders.length(); i++)
    {
      members.push_back(genders[i] == 'F' ? 0 : 1);
    }
    cin >> genders;
    for (int i = 0; i < genders.length(); i++)
    {
      fans.push_back(genders[i] == 'F' ? 0 : 1);
    }
    reverse(fans.begin(), fans.end());

    vector<int> res = karatsuba(members, fans);
    int ans = 0;
    int offset = members.size() - 1;
    for (int i = offset; i < res.size() - offset; i++)
    {
      ans += (res[i] == 0 ? 1 : 0);
    }
    cout << ans << '\n';
  }

  return 0;
}
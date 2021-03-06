// #include <iostream>
// #include <vector>

// using namespace std;

// int n, m;
// int ans;
// vector<int> wood;

// void search(int start, int end)
// {
//   int mid = (start + end) / 2;
//   if (start >= end)
//   {
//     ans = start;
//     return;
//   }
//   long long temp = 0;
//   for (int i = 0; i < n; i++)
//   {
//     if (wood[i] <= mid)
//       continue;
//     temp += wood[i] - mid;
//   }

//   if (temp == m)
//   {
//     cout << mid;
//     return;
//   }
//   else if (temp < m)
//   {
//     search(start, mid - 1);
//   }
//   else
//   {
//     search(mid + 1, end);
//   }
// }

// int main()
// {
//   cin >> n >> m;
//   wood.resize(n);
//   int min = 1000000001, max = 0;
//   for (int i = 0; i < n; i++)
//   {
//     scanf(" %d", &wood[i]);
//     if (min > wood[i])
//       min = wood[i];
//     if (max < wood[i])
//       max = wood[i];
//   }

//   search(0, max + 1);

//   return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree;

bool check(long long h, long long m)
{
  long long sum = 0;
  for (int i = 0; i < tree.size(); i++)
  {
    long long take = tree[i] - h;
    if (take > 0)
      sum += take;
  }
  if (sum >= m)
    return true;
  else
    return false;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, m;
  cin >> n >> m;
  tree.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> tree[i];
  }
  long long s = 0, e = 1000000001;
  while (e - s > 1)
  {
    int mid = (e + s) / 2;
    if (check(mid, m))
      s = mid;
    else
      e = mid;
  }
  cout << s;
  return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void print_seqeunce(vector<pair<int, int>> &numbers_cnt, const int target_size, vector<int> &visited, vector<int> &candidate, int candidate_size)
{
  if (target_size == candidate_size)
  {
    for (int number : candidate)
    {
      cout << number << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < numbers_cnt.size(); ++i)
  {
    if (visited[i] == numbers_cnt[i].second)
      continue;
    visited[i] += 1;
    candidate.push_back(numbers_cnt[i].first);
    print_seqeunce(numbers_cnt, target_size, visited, candidate, candidate_size + 1);
    visited[i] -= 1;
    candidate.pop_back();
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> numbers(n);
  vector<pair<int, int>> numbers_cnt;
  vector<int> visited;
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  sort(numbers.begin(), numbers.end());
  for (int i = 0; i < n; i++)
  {
    if (!numbers_cnt.empty() && numbers_cnt.back().first == numbers[i])
    {
      numbers_cnt.back().second++;
      continue;
    }
    numbers_cnt.push_back({numbers[i], 1});
    visited.push_back(0);
  }
  vector<int> candidate;
  print_seqeunce(numbers_cnt, m, visited, candidate, 0);
}
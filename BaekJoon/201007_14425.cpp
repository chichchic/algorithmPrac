#include <iostream>
#include <string>

using namespace std;

const int ALPHA = 'z' - 'a' + 1;

class Trie_node
{
private:
  bool end;
  Trie_node *child[ALPHA];

public:
  Trie_node()
  {
    end = false;
    for (int i = 0; i < ALPHA; i++)
    {
      child[i] = nullptr;
    }
  }

  ~Trie_node()
  {
    for (int i = 0; i < ALPHA; i++)
    {
      if (child[i] != nullptr)
        delete child[i];
    }
  }

  void insert(const char *str)
  {
    if (*str == '\0')
    {
      end = true;
      return;
    }
    int cur = *str - 'a';
    if (child[cur] == nullptr)
      child[cur] = new Trie_node();
    child[cur]->insert(str + 1);
  }

  bool find(const char *str)
  {
    if (*str == '\0')
    {
      if (end)
        return true;
      else
        return false;
    }
    int cur = *str - 'a';
    if (child[cur] == nullptr)
      return false;
    return child[cur]->find(str + 1);
  }
};

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Trie_node trie;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    trie.insert(str.c_str());
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    string str;
    cin >> str;
    if (trie.find(str.c_str()))
    {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
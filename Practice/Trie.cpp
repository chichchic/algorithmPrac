#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int ALPABATS = 26;

class Tri_Node
{
private:
  Tri_Node *child[ALPABATS];

public:
  Tri_Node()
  {
    for (int i = 0; i < ALPABATS; i++)
      child[i] = NULL;
  }

  ~Tri_Node()
  {
    for (int i = 0; i < ALPABATS; i++)
    {
      if (child[i] != NULL)
        delete child[i];
    }
  }

  int toNum(char c)
  {
    return tolower(c) - 'a';
  }

  void insert(const char *words)
  {
    if (*words == '\0')
    {
      cout << endl;
      return;
    }
    cout << *words;
    int next = toNum(*words);

    if (child[next] == NULL)
    {
      child[next] = new Tri_Node();
    }
    child[next]->insert(words + 1);
  }
  bool find(const char *words)
  {
    int next = toNum(*words);

    if (*words == '\0')
      return true;
    if (child[next] == NULL)
      return false;
    return child[next]->find(words + 1);
  }
};

int main()
{
  Tri_Node tri;
  tri.insert("like");

  if (tri.find("like"))
    cout << true << endl;
  else
  {
    cout << false << endl;
  }

  if (tri.find("bile"))
    cout << true << endl;
  else
  {
    cout << false << endl;
  }
}
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;

    while(n--)
    {
        vector<char> stack;
        string str;
        cin >> str;
        int input_len = str.length();

        if(input_len % 2 != 0)
            continue;
        
        for(int i = 0; i < input_len; i++)
        {
            stack.push_back(str[i]);
            if(stack.size() >= 2)
            {
                char temp = stack.back();
                stack.pop_back();
                if(stack.back() == temp)
                {
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(temp);
                }
            }
        }
        if(stack.empty())
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int test_case;
    cin >> test_case;

    while(test_case--)
    {
        vector<int> input;
        int size;
        cin >> size;
        vector<int> output;

        while(size)
        {
            int temp;
            bool ins = true;
            cin >>temp;
            for(vector<int>::iterator it = input.begin(); it != input.end(); it++)
            {
                if(*it > temp)
                {
                    input.insert(it,temp);
                    ins = false;
                    break;
                }
            }
            if(ins)
                input.push_back(temp);
            if(size%2 != 0)
            {
                output.push_back(*(input.begin()+(input.size()/2)));
            }
            size--;
        }
        cout << output.size() << endl;
        for(int i = 0; i < output.size(); i++)
            cout << output[i] << " ";
        cout << endl;
    }
    return 0;
}
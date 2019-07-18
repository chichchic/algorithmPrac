// #include <iostream>
// #include <list>

// using namespace std;

// int main()
// {
//     int n, k, cnt = 1;
//     cin >> n >> k;
//     list<int> circle;
//     for(int i = 1; i <= n; i++)
//         circle.push_back(i);

//     cout << "<";

//     list<int>::iterator itr = circle.begin();
//     list<int>::iterator temp = itr;
//     while(circle.size() > 1)
//     {
//         while(cnt != k)
//         {                
//             itr++;
//             cnt++;
//             if(itr == circle.end())
//                 itr = circle.begin();
//         }
//         cout << *itr << ", ";
//         temp = circle.erase(itr);
//         itr = temp;
//         cnt = 1;
//         if(itr == circle.end())
//                 itr = circle.begin();
//     }
//     cout << *itr << ">" << endl;
//     return 0;
// }

// //시간초과


//정답 코드
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, idx, remain;
    cin >> n >> k;
    vector<int> input;
    for(int i = 1; i <=n; i++)
        input.push_back(i);

    remain = n;
    idx = k-1;
    cout << "<";

    while(!input.empty())
    {
        cout << input[idx];
        input.erase(input.begin()+idx);
        remain--;
        idx += (k-1);

        if(!input.empty())
        {
            cout << ", ";
            if(idx >= remain)
            {
                idx %= remain;
            }
        }
        
        else
        {
            cout <<">";
        }

    }



    return 0;
}
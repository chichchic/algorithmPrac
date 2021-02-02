//시간초과
/*
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    list<pair<int, string> > input;

    int n;
    cin >> n;
    list<pair<int, string> >::iterator iter;
    while(n--)
    {
        int age;
        string name;
        bool input_check = true;
        cin >> age >> name;
        
        for(iter= input.begin(); iter != input.end(); iter++)
        {
            if((*iter).first > age)
            {
                input.insert(iter, make_pair(age, name));
                input_check = false;
                break;
            }
        }
        if(input_check)
        {
            input.insert(iter, make_pair(age, name));
        }
    }

    for(iter= input.begin(); iter != input.end(); iter++)
    {
        printf("%d %s\n", (*iter).first, (*iter).second.c_str());
    }

    return 0;
}
*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

class members{
    int age;
    string name;

    public:
        members(int age, string name)
            : age(age), name(name){}

    bool operator<(const members& t) const{
        return age < t.age;
    }

    friend ostream& operator<<(ostream& o, const members& mem);

};

ostream& operator<<(ostream& o, const members& mem)
{
    o << mem.age << " " << mem.name;
    return o;
}

int main()
{
    int n;
    cin >> n;
    multiset<members> member_chart;

    for(int i = 0; i < n; i++)
    {
        int temp_num;
        string temp_name;
        cin >> temp_num >> temp_name;
        member_chart.insert(members(temp_num, temp_name));
    }

    for(const auto& el : member_chart)
        cout << el << '\n';   //endl을 사용할 경우 시간초과. 관련 링크 : https://www.acmicpc.net/blog/view/57
    return 0;
}



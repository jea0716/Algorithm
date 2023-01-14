#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_case;
    cin >> num_case;
    for (int k = 0; k < num_case; k++)
    {
        int n;
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            char c;
            int tmp;
            cin >> c >> tmp;
            if(c == 'I')
            {
                s.insert(tmp);
            }
            else if(c == 'D')
            {
                if(s.empty())
                    continue;
                else if(tmp == 1){
                    s.erase(--s.end());
                }
                else if(tmp == -1)
                {
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty())
            cout << "EMPTY" << '\n';
        else 
        {
            cout << *(--s.end()) << " " << *s.begin() << '\n';
        }
    }
}
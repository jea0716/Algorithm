#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num_case; cin >> num_case;
    for(int i=0; i<num_case; i++)
    {
        vector <string> v(0);
        int tmp, len = 0; string s, sa; cin >> s >> tmp >> sa;
        for(int j=1; j<sa.length(); j++)
        {
            if((sa[j] == ',' || sa[j] == ']') && tmp > 0)
            {
                v.push_back(sa.substr(j-len, len));
                len = 0;
            }
            else if(sa[j] >= '0' && sa[j] <= '9')
            {
                len++;
            }
        }

        bool rev = false;
        int cnt = tmp;
        int left = 0, right = tmp-1;

        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == 'R')
            {
                rev = (rev == false ? true : false);
            }
            if(s[j] == 'D')
            {
                cnt--;
                if(cnt >= 0)
                {
                    if(rev == false) left++;
                    else right--;
                }
            }
        }
        if(cnt < 0) cout << "error\n";
        else
        {   
            cout << '[';
            if(rev == false){
                for(int j=left; j<=right; j++)
                {
                    cout << v[j];
                    if(j != right) cout << ',';
                }
            }
            else
            {
                for(int j=right; j>=left; j--)
                {
                    cout << v[j];
                    if(j != left) cout << ',';
                }                
            }
            cout << "]\n";
        }
    }
}
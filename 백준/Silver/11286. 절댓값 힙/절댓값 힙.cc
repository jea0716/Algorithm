#include <iostream>
#include <queue>

using namespace std;

priority_queue <int> m;
priority_queue <int, vector<int>, greater<int> > p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, tmp; cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        if(tmp == 0)
        {
            if(m.size() == 0 && p.size() == 0) cout << 0 << '\n';
            else if(m.size() == 0 && p.size() != 0)
            {   
                int t = p.top();
                p.pop();
                cout << t << '\n';
            }
            else if(m.size() != 0 && p.size() == 0)
            {
                int t = m.top();
                m.pop();
                cout << t << '\n';
            }
            else
            {
                int t1 = -(m.top()), t2 = p.top();
                if(t1 <= t2)
                {
                    cout << -t1 << '\n';
                    m.pop();
                }
                else
                {
                    cout << t2 << '\n'; 
                    p.pop();
                }
            }
        }
        else if(tmp > 0)
        {
            p.push(tmp);
        }
        else
        {
            m.push(tmp);
        }
    }
    return 0;
}
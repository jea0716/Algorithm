#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

struct props{
    int first;
    string second;
};

int N, A, B;
string S;
props visited[10000];

void solve(int start_num, string s)
{
    queue <props> q;
    props start;
    start.first = start_num;
    start.second = s;
    q.push(start);

    while(!q.empty())
    {
        int x = q.front().first;
        q.pop();

        if(x == B) return;

        props tmp;

        if(visited[(2 * x) % 10000].first == 0 && x != 0)
        {
            tmp.first = (2 * x) % 10000;
            tmp.second = visited[x].second;
            tmp.second.append("D");
            visited[(2 * x) % 10000].first = 1;
            if(visited[(2 * x) % 10000].second.length() > tmp.second.length() || visited[(2 * x) % 10000].second == "")
            {
                visited[(2 * x) % 10000].second = tmp.second;
            }
            q.push(tmp);
        }

        int minus = x - 1;
        if(minus == -1) minus = 9999;
        if(visited[minus].first == 0)
        {
            tmp.first = minus;
            tmp.second = visited[x].second;
            tmp.second.append("S");
            visited[minus].first = 1;
            if(visited[minus].second.length() > tmp.second.length() || visited[minus].second == "")
            {
                visited[minus].second = tmp.second;
            }
            q.push(tmp);
        }

        int z = x;
        int a = z % 10; z /= 10;
        int b = z % 10; z /= 10;
        int c = z % 10; z /= 10;
        int d = z;

        int move_left = c * 1000 + b * 100 + a * 10 + d;
        int move_right = a * 1000 + d * 100 + c * 10 + b;

        if(visited[move_left].first == 0)
        {
            tmp.first = move_left;
            tmp.second = visited[x].second;
            tmp.second.append("L");
            visited[move_left].first = 1;
            if(visited[move_left].second.length() > tmp.second.length() || visited[move_left].second == "")
            {
                visited[move_left].second = tmp.second;
            }
            q.push(tmp);
        }

        if(visited[move_right].first == 0)
        {
            tmp.first = move_right;
            tmp.second = visited[x].second;
            tmp.second.append("R");
            visited[move_right].first = 1;
            if(visited[move_right].second.length() > tmp.second.length() || visited[move_right].second == "")
            {
                visited[move_right].second = tmp.second;
            }
            q.push(tmp);
        }
    }
}

int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<10000; j++)
        {
            visited[j].first = 0;
            visited[j].second = "";
        }
        cin >> A >> B;
        S = "";
        solve(A, S);
        cout << visited[B].second << endl;
    }

    return 0;
}
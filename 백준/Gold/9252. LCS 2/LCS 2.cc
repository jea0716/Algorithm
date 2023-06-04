#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b, answer;

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();

    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    a = ' ' + tmp1; b = ' ' + tmp2;

    for(int i=1; i<b.size(); i++)
    {
        for(int j=1; j<a.size(); j++)
        {
            if(a[j] == b[i]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int x = a.size() - 1, y = b.size() - 1;

    while(dp[y][x])
    {
        if(dp[y][x] == dp[y-1][x]) y -= 1;
        else if(dp[y][x] == dp[y][x-1]) x -= 1;
        else
        {
            answer += a[x];
            y -= 1; x -= 1;
        }
    }

    cout << dp[b.size()-1][a.size()-1] << "\n";
    if(answer.size() > 0) 
    {
        reverse(answer.begin(), answer.end());
        cout << answer << "\n";
    }

    return 0;
}
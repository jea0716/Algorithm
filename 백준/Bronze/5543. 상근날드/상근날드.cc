#include <iostream>
#include <algorithm>

using namespace std;

string a, b, answer;

int dp[1001][1001];

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int answer = min(a, b);
    answer = min(answer, c);
    int d, e; cin >> d >> e;
    if(d > e) answer += e - 50;
    else answer += d - 50;
    cout << answer << endl;
}
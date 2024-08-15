#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
long long int dp[100];

/*

1-1 - 1
2-1 - 10
3-2 - 101 100
4-3 - 1000 1001 1010
5-5 - 10000 10001 10010 10100 10101
6-8 - 100000 100001 100010 100100 100101 101000 101001 101010
7-13 -1000000 1000001 1000010 1000100 1001000 1010000 1000101 1001001 1001010 1010001 1010010 1010100 1010101

*/

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    dp[1] = 1;
    for(int i=2; i<=N; i++) dp[i] = dp[i-1] + dp[i-2];

    cout << dp[N] << '\n';

    return 0;
}
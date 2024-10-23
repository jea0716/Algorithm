#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    int s = 1, e = K, m, cnt;

    while(s < e) 
    {
        m = (s + e) / 2, cnt = 0;

        for(int i=1; i<=N; i++)
        {
            cnt += min(N, m / i);
        }

        if(cnt >= K) e = m;
        else s = m + 1;
    }

    cout << e << endl;

    return 0;
}
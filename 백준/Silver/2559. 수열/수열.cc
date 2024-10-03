#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K, tmp, answer = -999999999;
vector<int> v(1, 0);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    for(int i=0; i<N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0; i<=N; i++)
    {
        v[i] += v[i-1];
    }

    for(int i=0; i<=N-K; i++)
    {
        if(answer < v[i + K] - v[i]) 
        {
            answer = v[i + K] - v[i];
        }
    }

    cout << answer << "\n";

    return 0;
}
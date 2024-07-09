#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, tmp;
long long answer, sum;
vector<long long> v(1001, 0);

int main() {
    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        cin >> tmp;
        sum = (sum + tmp) % M;
        if(sum == 0) answer++;
        v[sum]++;
    }

    for(int i=0; i<M; i++) {
        answer += v[i] * (v[i] - 1) / 2;
    }

    cout << answer << '\n';

    return 0;
}
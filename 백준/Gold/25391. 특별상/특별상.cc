#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct node {
    int a, b;
    bool c;
};

int N, M, K, A, B;
long long answer;
vector<node> v;

bool cmpA(node n1, node n2) {
    return n1.a > n2.a;
}

bool cmpB(node n1, node n2) {
    if(n1.b == n2.b) return n1.a > n2.a;
    return n1.b > n2.b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {
        cin >> A >> B;
        v.push_back({ A, B, false });
    }

    sort(v.begin(), v.end(), cmpB);

    for(int i=0; i<K; i++) {
        answer += v[i].a;
        v[i].c = true;
    }

    int n = 0, num = 0;
    sort(v.begin(), v.end(), cmpA);
    while(num < M) {
        if(!v[n].c) {
            answer += v[n].a;
            v[n].c = true;
            num++;
        }

        n++;
    }

    cout << answer << '\n';

    return 0;
}   
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, tmp;
int minus_arr[4001], plus_arr[4001];
vector<int> v;
vector<int> vv;
double sum = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        if(tmp >= 0) plus_arr[tmp]++;
        else minus_arr[tmp * -1]++;
        v.push_back(tmp);
        sum += tmp;
    }

    int round_num = round(sum / N);
    if(round_num == -0) round_num = 0;

    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i=0; i<=4000; i++) {
        if(plus_arr[i] > cnt) cnt = plus_arr[i];
        if(minus_arr[i] > cnt) cnt = minus_arr[i];
    }

    for(int i=0; i<=4000; i++) {
        if(cnt == plus_arr[i]) vv.push_back(i);
        if(cnt == minus_arr[i]) vv.push_back(i * -1);
    }
    
    sort(vv.begin(), vv.end());
    int ans = 0;
    if(vv.size() == 1) ans = vv[0];
    else ans = vv[1];

    cout << round_num << '\n' << v[N / 2] << '\n' << ans << '\n' << v[N - 1] - v[0] << '\n';

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, max_num, location;
vector<int> arr(1001);
vector<int> dp(1001);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++) cin >> arr[i];

    for(int i=0; i<N; i++) {
        int cnt = 0;
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                cnt = cnt > dp[j] ? cnt : dp[j];
            }
        }
        dp[i] = cnt + 1;
        if(max_num < dp[i]) {
            max_num = dp[i];
            location = i;
        }
        max_num = max_num > dp[i] ? max_num : dp[i];
    }

    
    cout << max_num << '\n';
    int tmp = max_num;
    vector<int> v;
    for(int i=location; i>=0; i--) {
        if(dp[i] == tmp) {
            tmp--;
            v.push_back(arr[i]);
        }
    }
    for(int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
    cout << "\n";

    return 0;
}
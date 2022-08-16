#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];

int main(){
    int n, w, answer=0; cin >> n >> w;
    vector <pair<int, int> > arr;
    int temp1, temp2;

    for(int i=0; i<n; i++){
        cin >> temp1 >> temp2;
        arr.push_back(make_pair(temp1, temp2));
    }

    for(int i=0; i<arr.size(); i++){
        for(int j=w; j>=arr[i].first; j--){
            dp[j] = max(dp[j], dp[j-arr[i].first]+arr[i].second);
        }
    }

    for(int i=0; i<=w; i++){
        if(answer < dp[i]) answer = dp[i];
    }

    cout << answer << '\n';


    return 0;
}
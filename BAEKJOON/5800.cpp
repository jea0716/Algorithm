#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n; cin >> n;
    int temp, gap = 0;
    vector <int> arr;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for(int i=1; i< arr.size(); i++){
        if(arr[i] - arr[i-1] > gap) gap = arr[i] - arr[i-1];
    }
    cout << "Max " << arr.back() << ", Min " << arr.front() << ", Largest gap " << gap << '\n';
}

int main(){
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        cout << "Class " << i+1 << '\n';
        solve();
    }
    return 0;
}
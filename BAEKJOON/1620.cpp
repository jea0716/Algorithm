#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int> > sorted_dogam;

int binary(int min, int max, string name){
    while(min <= max){
        int mid = (min + max) / 2;
        if(sorted_dogam[mid].first == name) return sorted_dogam[mid].second;
        else if(sorted_dogam[mid].first > name) max = mid - 1;
        else min = mid + 1;
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    map <int, string> arr;
    string name;
    for(int i=1; i<=n; i++){
        cin >> name;
        sorted_dogam.push_back(pair<string, int>(name, i));
        arr.insert(make_pair(i, name));
    }
    sort(sorted_dogam.begin(), sorted_dogam.end());
    vector <int> a;
    for(int i=0; i<m; i++){
        cin >> name;
        if(int(name[0])>48 && int(name[0])<58){
            int num = stoi(name);
            cout << arr[num] << '\n';
        }
        else{
            cout << binary(0, n-1, name) << '\n';
        }
    }
    return 0;
}
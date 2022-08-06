#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(){
    int n; cin >> n;
    vector <pair<string, int> > num;
    string name, type; 
    int answer = 1;
    for(int i=0; i<n; i++){
        cin >> name >> type;
        if(i==0) num.push_back(make_pair(type,1));
        for(int j=0; j<num.size(); j++){
            if(num[j].first == type){
                num[j].second += 1;
                break;
            }
            if(j==num.size()-1) num.push_back(make_pair(type,1));
        }
    }
    for(int i=0; i<num.size(); i++){
        answer *= num[i].second;
    }

    answer -= 1;
    cout << answer << '\n';
    return ;
}

int main(){
    int N; cin >> N;
    for(int i=0; i<N; i++) solve();
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num; cin >> n >> num;
    int answer = 0;
    string s = "I";
    for(int i=0; i<n; i++){
        s += "OI";
    }
    string line; cin >> line;
    
    for(int i=0; i<line.length()-((2*n)+1); i++){
        if(s == line.substr(i,2*n+1)) answer++;
    }

    cout << answer << endl;
}
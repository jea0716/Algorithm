#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    map <string, string> arr;

    string addr, pwd;
    for(int i=0; i<n; i++){
        cin >> addr >> pwd;
        arr.insert(make_pair(addr, pwd));
    }

    for(int i=0; i<m; i++){
        cin >> addr;
        cout << arr[addr] << '\n';
    }
}
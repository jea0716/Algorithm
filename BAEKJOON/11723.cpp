#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[21];

void add(){
    int n; cin >> n;
    arr[n] = 1;
    return ;
}

void remove(){
    int n; cin >> n;
    arr[n] = 0;
    return ;
}

void check(){
    int n; cin >> n;
    if(arr[n] == 1) cout << "1" << '\n';
    else cout << "0" << '\n';
    return ;
}

void toggle(){
    int n; cin >> n;
    if(arr[n] == 1) arr[n] = 0;
    else arr[n] = 1;
}

void all(){
    for(int i=1; i<21; i++) arr[i] = 1;
}

void empty(){
    for(int i=1; i<21; i++) arr[i] = 0;
}

int main(){
    int n; cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s == "add") add();
        if(s == "remove") remove();
        if(s == "check") check();
        if(s == "toggle") toggle();
        if(s == "all") all();
        if(s == "empty") empty();
    }
    return 0;
}
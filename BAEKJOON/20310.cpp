#include <iostream>
#include <string>

using namespace std;

int arr[501];

int main(){
    string s, answer = ""; cin >> s;
    int zero_count = 0, one_count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0') zero_count++;
        else one_count++;
    }
    one_count /= 2; zero_count /= 2;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1' && one_count != 0){
            one_count--;
            arr[i] = 1;
        }
    }
    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == '0' && zero_count != 0){
            zero_count--;
            arr[i] = 1;
        }
    }
    for(int i=0; i<s.length(); i++){
        if(arr[i] == 0) answer += s[i];
    }

    cout << answer << endl;

    return 0;
}
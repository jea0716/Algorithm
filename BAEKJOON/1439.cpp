#include <iostream>
#include <string>

using namespace std;
int main(){
    string s; cin >> s;
    int count = 0;
    bool on = false;
    for(int i=0; i<s.length()-1; i++){
        if(s[i] != s[i+1]){
            if(on == false){
                on = true;
                count++;
            }
            else{
                on = false;
            }
        }
    }
    cout << count << endl;
}
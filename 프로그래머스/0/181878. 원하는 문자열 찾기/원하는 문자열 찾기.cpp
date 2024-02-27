#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(int i=0; i<myString.length(); i++) {
        if(myString[i] >= 'A' && myString[i] <= 'Z') myString[i] += 32;
    }
    
    for(int i=0; i<pat.length(); i++) {
        if(pat[i] >= 'A' && pat[i] <= 'Z') pat[i] += 32;
    }
    
    if(myString.length() >= pat.length()) {
        for(int i=0; i<=myString.length() - pat.length(); i++) {
            bool check = true;
            for(int j=0; j<pat.length(); j++) {
                if(myString[i+j] != pat[j]) check = false;
            }
            if(check) answer = 1;
        }
    }
    
    return answer;
}
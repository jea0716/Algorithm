#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0; i<=t.length()-p.length(); i++) {
        string tmp = "";
        for(int j=0; j<p.length(); j++) tmp += t[i+j];
        if(p >= tmp) answer++;
    }
    return answer;
}
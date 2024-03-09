#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;

    for(int i=1; i<A.length(); i++) {
        string tmp = "";
        for(int j=i; j<A.length(); j++) tmp += A[j];
        for(int j=0; j<i; j++) tmp += A[j];
        
        if(tmp == B) answer = i;
    }
    
    if(A == B) answer = 0;
    else if(answer == 0) answer = -1;
    else answer = A.length() - answer;
    return answer;
}
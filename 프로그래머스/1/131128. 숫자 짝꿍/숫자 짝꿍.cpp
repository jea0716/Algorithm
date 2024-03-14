#include <string>
#include <vector>

using namespace std;

int arrX[10], arrY[10];

string solution(string X, string Y) {
    string answer = "";
    for(int i=0; i<X.length(); i++) arrX[X[i] - '0']++;
    for(int i=0; i<Y.length(); i++) arrY[Y[i] - '0']++;
    for(int i=9; i>=0; i--) {
        // answer += to_string(arrX[i]);
        // answer += to_string(arrY[i]);
        if(arrX[i] > 0 && arrY[i] > 0) {
            int min = arrX[i] > arrY[i] ? arrY[i] : arrX[i];
            for(int j=0; j<min; j++) {
                answer += to_string(i);
            }
        }
    }
    if(answer == "") answer = "-1";
    bool check = true;
    for(int i=0; i<answer.length(); i++) {
        if(answer[i] != '0') check = false;
    }
    if(check) answer = "0";
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int arr[31];

int solution(vector<string> strArr) {
    int answer = 0;
    for(int i=0; i<strArr.size(); i++) {
        arr[strArr[i].length()]++;
    }
    for(int i=0; i<31; i++) if(answer < arr[i]) answer = arr[i];
    return answer;
}
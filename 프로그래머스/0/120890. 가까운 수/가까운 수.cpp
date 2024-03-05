#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int diff = 999;
    for(int i=0; i<array.size(); i++) {
        if(abs(array[i] - n) < diff) diff = abs(array[i] - n), answer = array[i];
        else if(abs(array[i] - n) == diff && answer > array[i]) answer = array[i]; 
    }
    return answer;
}
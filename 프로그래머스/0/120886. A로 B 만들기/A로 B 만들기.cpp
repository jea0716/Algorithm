#include <string>
#include <vector>

using namespace std;

int arr[30];

int solution(string before, string after) {
    int answer = 1;
    for(int i=0; i<before.length(); i++) arr[before[i] - 'a']++;
    for(int i=0; i<after.length(); i++) arr[after[i] - 'a']--;
    for(int i=0; i<30; i++) if(arr[i] < 0) answer = 0;
    return answer;
}
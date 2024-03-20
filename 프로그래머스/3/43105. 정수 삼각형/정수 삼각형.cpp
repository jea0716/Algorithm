#include <string>
#include <vector>

using namespace std;

int arr[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    arr[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            if(j == 0) {
                arr[i][j] = triangle[i][j] + arr[i-1][j];
            }
            else if(j == triangle[i].size()-1) {
                arr[i][j] = triangle[i][j] + arr[i-1][j-1];
            }
            else {
                int max = arr[i-1][j] > arr[i-1][j-1] ? arr[i-1][j] : arr[i-1][j-1];
                arr[i][j] = triangle[i][j] + max;  
            }
        }
    }
    for(int i=0; i<triangle.size(); i++) {
        int tmp = arr[triangle.size()-1][i];
        answer = answer > tmp ? answer : tmp;
    }
    
    return answer;
}
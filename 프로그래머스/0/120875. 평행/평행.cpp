#include <string>
#include <vector>

using namespace std;

double gradient(int x1, int x2, int y1, int y2){  // 기울기 구하기
    return (double)(x2 - x1) / (double)(y2 - y1);
}

int solution(vector<vector<int>> dots) {
    
    if(gradient(dots[0][0], dots[1][0], dots[0][1], dots[1][1]) == gradient(dots[2][0], dots[3][0], dots[2][1], dots[3][1])) return 1;
    if(gradient(dots[0][0], dots[2][0], dots[0][1], dots[2][1]) == gradient(dots[1][0], dots[3][0], dots[1][1], dots[3][1])) return 1;
    if(gradient(dots[0][0], dots[3][0], dots[0][1], dots[3][1]) == gradient(dots[2][0], dots[1][0], dots[2][1], dots[1][1])) return 1;
    
    return 0;
}
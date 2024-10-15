#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
	long long answer = 0;

	for (int i = 1; i <= r2; i++) {
		int minY = ceil(sqrt((long long)r1 * r1 - (long long)i * i));
		int maxY = floor(sqrt((long long)r2 * r2 - (long long)i * i));

		if (r1 < i)
			minY = 0;

		answer += (maxY - minY + 1);
	}

	return answer * 4;
}
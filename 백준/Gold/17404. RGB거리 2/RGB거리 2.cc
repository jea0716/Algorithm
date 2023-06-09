#include <iostream>
#include <algorithm>

using namespace std;

int N;
int f_R, f_G, f_B;
int l_R, l_G, l_B;
int R, G, B;
int A1[3], A2[3], A3[3];
int t1, t2, t3;
int answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    cin >> f_R >> f_G >> f_B;

    A1[0] = f_R;        A1[1] = 99999999;   A1[2] = 99999999;
    A2[0] = 99999999;   A2[1] = f_G;    A2[2] = 99999999;
    A3[0] = 99999999;   A3[1] = 99999999;   A3[2] = f_B;

    for (int i = 1; i < N - 1; i++)
    {
        cin >> R >> G >> B;

        t1 = A1[0], t2 = A1[1], t3 = A1[2];

        A1[0] = min(t2, t3) + R;
        A1[1] = min(t1, t3) + G;
        A1[2] = min(t1, t2) + B;

        t1 = A2[0], t2 = A2[1], t3 = A2[2];

        A2[0] = min(t2, t3) + R;
        A2[1] = min(t1, t3) + G;
        A2[2] = min(t1, t2) + B;

        t1 = A3[0], t2 = A3[1], t3 = A3[2];

        A3[0] = min(t2, t3) + R;
        A3[1] = min(t1, t3) + G;
        A3[2] = min(t1, t2) + B;
    }

    cin >> l_R >> l_G >> l_B;

    t1 = A1[0], t2 = A1[1], t3 = A1[2];

    A1[1] = min(t1, t3) + l_G;
    A1[2] = min(t1, t2) + l_B;

    answer = min(A1[1], A1[2]);

    t1 = A2[0], t2 = A2[1], t3 = A2[2];

    A2[0] = min(t2, t3) + l_R;
    A2[2] = min(t1, t2) + l_B;

    answer = min(answer, min(A2[0], A2[2]));

    t1 = A3[0], t2 = A3[1], t3 = A3[2];

    A3[0] = min(t2, t3) + l_R;
    A3[1] = min(t1, t3) + l_G;

    answer = min(answer, min(A3[0], A3[1]));

    cout << answer << "\n";

    return 0;
}
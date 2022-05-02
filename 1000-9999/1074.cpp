#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int N;
    long long r, c;
    cin >> N >> r >> c;

    long long sum =0;

    for (int i=0; i<N; i++){
        // r, c를 2로 나눈 나머지를 이용해 계산
        sum += pow(4, i) * (2 * (r % 2) + 1 * (c % 2));

        r = r/2;
        c = c/2; 
    }

    cout << sum;
    return 0;
}
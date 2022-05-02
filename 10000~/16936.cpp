#include <iostream>
using namespace std;

void game(long long* arrayA, long long* arrayB, int N, long long x, long long k, int cnt){
    long long testNum;
    bool check = false;

    if (cnt == N-1) {
        arrayB[cnt] = x;
        return;
    }

    if (x % 3 == 0){
        // 3의 배수인 경우 x / 3 먼저 검증
        testNum = x / 3;

        for(int i = 0; i<N ; i++){
            if (testNum == arrayA[i]){
                arrayB[cnt++] = x;
                check = true;
                game(arrayA, arrayB, N, testNum, k, cnt);
            }
        }
    }
    
    // x * 2 검증
    testNum = x * 2;

    for(int i = 0; i<N ; i++){
        if (testNum == arrayA[i]){
            arrayB[cnt++] = x;
            check = true;
            game(arrayA, arrayB, N, testNum, k, cnt);
        }
    }

    if(!check){
        k++;
        game(arrayA, arrayB, N, arrayA[k], k, 0);
    }
}

int main(){
    int N;
    cin >> N;

    long long* arrayA = new long long[N];
    long long* arrayB = new long long[N];

    // 수열 A 입력 받음
    for (int i=0; i<N; i++){
        cin >> arrayA[i];
    }
       
    game(arrayA, arrayB, N, arrayA[0], 0, 0);

    for (int i=0; i<N; i++){
        cout << arrayB[i] << ' ';
    }

    // 배열 할당 해제
    delete[] arrayA;
    delete[] arrayB;

    return 0;
}
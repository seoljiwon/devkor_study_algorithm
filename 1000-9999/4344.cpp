#include <iostream>
#include <cmath>
using namespace std;
int main(){
    // 테스트 케이스 개수 입력 받음
    int caseCnt;
    cin >> caseCnt;

    // 테스트 케이스 개수 길이의 percentageCnt 배열, studentCnt 배열 동적 할당
    int * percentageCnt = new int[caseCnt];
    int * studentCnt = new int[caseCnt];

    for (int i=0; i<caseCnt; i++){
        // 학생 수 입력 받음
        cin >> studentCnt[i];

        // 입력 받은 학생 수 길이의 score 배열 동적 할당
        int * score = new int[studentCnt[i]];

        // score 입력 받으면서 전체 점수 계산
        int total = 0;
        for (int j=0; j<studentCnt[i]; j++){
            cin >> score[j];
            total += score[j];
        }

        // 평균 계산
        double avg = total/studentCnt[i];

        // score 배열에서 평균보다 높은 값을 갖는 점수 개수 계산
        percentageCnt[i] = 0;
        for (int j=0; j<studentCnt[i]; j++){
            if (score[j] > avg){
                percentageCnt[i] += 1;
            }
        }

        // score 배열 할당 해제
        delete[] score;
    }
    

    // percentage 출력
    for (int i=0; i<caseCnt; i++){
        // 퍼센트 표현을 위해 100, 소숫점 셋째 자리까지 출력하기 위해 1000을 곱하고 round 한 후 다시 1000으로 나눔
        double percentage = round(percentageCnt[i] * 100000)/(studentCnt[i]*1000);

        // 소수점 셋째 자리까지 출력
        cout << fixed;
        cout.precision(3);
        cout << percentage << '%' << '\n';
    }

    // percentageCnt 배열, studentCnt 배열 할당 해제
    delete[] percentageCnt;
    delete[] studentCnt;

    return 0;
}
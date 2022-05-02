#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 초기에 입력되어 있는 문자열
    string s;
    cin >> s;
    int len = s.length();

    // char형 list 선언 후 s 넣음
    list <char> l;

    for (int i = 0; i < len; i++){
        l.push_back(s[i]);
    }

    // 커서의 위치
    auto cursor = l.end();

    // 명령어의 개수
    int n;
    cin >> n;

    while(n--){
        // 입력할 명령어
        string command;
        cin >> command;

        if (command == "L"){
            if (cursor != l.begin()){
                cursor --;
            }
        } else if (command == "D"){
            if (cursor != l.end()){
                cursor ++;
            }
        } else if (command == "B"){
            if (cursor != l.begin()){
                cursor --;
                cursor = l.erase(cursor);
            }
        } else if (command == "P"){
            char c;
            cin >> c;

            l.insert(cursor, c);
        }
    }

    for (auto i = l.begin(); i != l.end(); i++){
        cout << *i;
    }
}
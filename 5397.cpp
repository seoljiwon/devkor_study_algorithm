#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    while(n--){
        string str;
        cin >> str;

        list <char> l;

        // 커서의 위치
        auto cursor = l.begin();
        
        int size = str.length();

        for (int i = 0; i < size; i++){
            if (str[i] == '<'){
                if (cursor != l.begin()){
                    cursor --;
                }
            } else if (str[i] == '>'){
                if (cursor != l.end()){
                    cursor ++;
                }
            } else if (str[i] == '-'){
                if (cursor != l.begin()){
                    cursor = l.erase(-- cursor);
                } 
            } else {
                l.insert(cursor, str[i]);
            }
        }

        for (auto i = l.begin(); i != l.end(); i++){
            cout << *i; 
        }
        cout << '\n';
    }
}
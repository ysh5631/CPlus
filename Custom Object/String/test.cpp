#include "String.h"

using namespace std;

int main() {
    String strs[] = {
            String{"C"},
            String{},
            String{"Java"}
    };

    strs[1] = "C++"; // 여기서 move 출력
    // 여기서 4줄 다 출력됨.

    const int arraySize = sizeof(strs) / sizeof(String);

    const String target("Java");
    for(int i=0; i<arraySize;i++){
        const String str(strs[i]);
        if(0 == str.compare(target)){
            cout << "[" << i << "]: ";
            cout << str.data() << "\n";
            break;
        }
    }
    for (const String& str:strs) cout << str.data() << "\n";

    return 0;

}
#include <iostream>

void increasement(int &x){
    x++;
}

double const_reference(const int &x){
    // x++; // erorr!
    std::cout << "x is " << x << "\n";
}

void default_value(double x, int y = 1) {
    double c = x + y;
}

inline void inline_reference(int &x){
    x++;
}

// int main();
// int main(int argc, char ** argv);
int main(int argc, char * argv[]){

    int i = 4;
    increasement(i);
    // increasement(i + 9); // error! 레퍼런스 인수는 임시 변수를 허용하지 않는다.

    std::cout << "i is " << i << "\n";

    const_reference(i);
    // 상수 레퍼런스는 임시 변수를 허용한다.
    const_reference(i + 9);

    // 함수 인자의 기본값
    default_value(3.5);
    default_value(3.5, 2);

    // 인라인 레퍼런스 변수?
    // 뭐가 다른거지
    inline_reference(i);
    const_reference(i);

    return 0;
}
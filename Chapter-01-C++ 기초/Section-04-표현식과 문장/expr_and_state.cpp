#include <iostream>
#include <cmath>

int main(int argc, char * argv[]){
    int x = -5, y = 2;
    int c;

    // expression
    // 표현식
    // x
    // abs(x)
    // pow(abs(x), y)
    c = pow(abs(x), y);
    std::cout << "c is " << c << "\n";

    // statement
    // 문장 - 끝에 세미콜론이 오는 표현식
    c = x + y;
    
    // c++11 이상
    // 범위 기반 for 문
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for(int i : primes){
        std::cout << i << "\n";
    }

    return 0;
}
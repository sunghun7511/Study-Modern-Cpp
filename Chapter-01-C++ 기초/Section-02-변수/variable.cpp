/*
Author : SHGroup(sunghun7511)
Github : https://github.com/sunghun7511
*/

#include <iostream>

#include <complex>
#include <string>

int main(int argc, char * argv[]){

    // C++ STL 에는 복소수(complex)타입이 있다.
    std::complex<float> z(1.3, 2.4), z2;
    z2 = 2.0f * z;

    std::cout << "Complex " << z2 << "\n";

    // 10진수가 아닌 숫자 리터럴들
    int oct = 042;          // int oct = 34;
    int hex = 0x10;         // int hex = 16;

    // C++14 이후에서는 비트표현이 가능하다.
    int bits = 0b11111010;  // int bits = 250;

    // C++14 이후에서는 가독성을 위해 '를 사용할 수 있다.
    double db = 1'234'567l;
    unsigned long ul = 0x123'4567'89ab'cdef;
    int bit = 0b101'1101'1100'0001'0010;
    const long double pi = 3.141'592'653'589'793'238'462l;

    // 문자열 리터럴은 char 배열로 할당하는 것보다는
    char strs[] = "Hello char[]!";

    // std::string 을 사용하는 것이 더 좋다.
    // 또한 여러 줄을 사용할 수 있다.
    std::string str = "Hello string!\n"
                        "And good luck!";


    // 축소하지 않는 초기화
    // 만약 타겟 아키텍처에서 값을 저장할 수 없다면 컴파일 오류를 출력한다.
    long l = { 1234567890123 };

    /*
    // int is_it_pi = { pi };
    /*
        ./new_learn.cpp: In function ‘int main(int, char**)’:
        ./new_learn.cpp:40:25: warning: narrowing conversion of ‘(long double)pi’ from ‘long double’ to ‘int’ inside { } [-Wnarrowing]
            int is_it_pi = { pi };
                                ^
    */

    /*
    // unsigned not_u = { -3 };
    /*
        ./new_learn.cpp: In function ‘int main(int, char**)’:
        ./new_learn.cpp:39:27: error: narrowing conversion of ‘-3’ from ‘int’ to ‘unsigned int’ inside { } [-Wnarrowing]
            unsigned not_u = { -3 };
                                ^
    */


    // 숨기기
    int value = 5;

    std::cout << "처음 value 값은 " << value << " 입니다.\n";
    {
        value = 3;
        std::cout << "블럭 안에서의 value 값은 " << value << " 입니다.\n";
        
        int value;
        value = 8;
        std::cout << "블럭 안에서의 새로운 value 값은 " << value << " 입니다.\n";
        {
            value = 7;
        }
        std::cout << "블럭이 끝나기 전의 value 값은 " << value << " 입니다.\n";
    }
    std::cout << "블럭이 끝난 이후의 value 값은 " << value << " 입니다.\n";
    value = 11;
    std::cout << "최종적으로 value 값은 " << value << " 입니다.\n";

    /*
        처음 value 값은 5 입니다.
        블럭 안에서의 value 값은 3 입니다.
        블럭 안에서의 새로운 value 값은 8 입니다.
        블럭이 끝나기 전의 value 값은 7 입니다.
        블럭이 끝난 이후의 value 값은 3 입니다.
        최종적으로 value 값은 11 입니다.
    */

    return 0;
}
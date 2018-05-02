/*
Author : SHGroup(sunghun7511)
Github : https://github.com/sunghun7511
*/

#include <iostream>

int main(int argc, char * argv[]){
    
    // 정밀도 손실의 예
    long l = 123456789012;
    long l2 = l + 1.0f - 1.0;    // 부정확하다
    long l3 = l + (1.0f - 1.0);  // 정확하다.

    std::cout << "Original : " << l << "\n";
    std::cout << "l + 1.0f - 1.0 : " << l2 << "\n";
    std::cout << "l + (1.0f - 1.0) : " << l3 << "\n";

    /*
        Original : 123456789012
        l + 1.0f - 1.0 : 123456790527
        l + (1.0f - 1.0) : 123456789012
    */


    // 개체(수정 가능한 Lvalue)의 값은 할당 연산자를 통해 설정할 수 있다.
    int a, b, c, d = 3;

    // 다음과 같이 붙여쓸 수 있다.
    a = b = c = d;

    // 위와 아래 코드는 같다.
    a *= b + c;
    a = a * (b + c);


    // Comma Operator
    std::cout << "콤마 연산자의 결과값\n 3 + 4, 7 * 9.3 = " << (3 + 4, 7 * 9.3) << "\n";

    /*
        콤마 연산자의 결과값
         3 + 4, 7 * 9.3 = 65.1
    */
    
    auto x = 5;
    auto y = 0x1234'5678'90ab'cdef;
    int z[] = {1, 2, 3, 4, 5};

    std::cout << "sizeof(x) : " << sizeof(x) << "\n";
    std::cout << "sizeof(y) : " << sizeof(y) << "\n";
    std::cout << "sizeof(z) : " << sizeof(z) << "\n";
    std::cout << "sizeof(z[0]) : " << sizeof(z[0]) << "\n";

    std::cout << "alignof(x) : " << alignof(x) << "\n";
    std::cout << "alignof(y) : " << alignof(y) << "\n";
    std::cout << "alignof(z) : " << sizeof(z) << "\n";
    std::cout << "alignof(z[0]) : " << alignof(z[0]) << "\n";

    /*
        sizeof(x) : 4
        sizeof(y) : 8
        sizeof(z) : 20
        sizeof(z[0]) : 4
        alignof(x) : 4
        alignof(y) : 8
        alignof(z) : 20
        alignof(z[0]) : 4
    */
    

    return 0;
}
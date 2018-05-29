#include <iostream>
#include <fstream>
#include <cstdlib>

// #define NDEBUG
// 다음과 같이 NDEBUG를 정의하면 모든 단정을 비활성화한다.
// 또는 리눅스에너는 -D, 윈도우에서는 /D 옵션을 사용할 수도 있다.
#include <cassert>


struct cannot_open_file { };

int read_file(const char * name){
    std::fstream f(name);
    if(!f.is_open()){
        // throw "Cannot open file";
        throw cannot_open_file{ };
    }

    // ...

    return 0;
}

// 함수에서 예외를 던지지 않아야 한다는 걸 지정하는 지정자 : noexcept
double squalre_root(double x) noexcept {
    
    // ...

    return 0.0f;
}

int main(int argc, char * argv[]){

    int i = 0;

    printf("Input i : ");
    scanf("%d", &i);
    
    // 단정(assert)
    // 아래 경우에는 i가 0보다 작으면 프로그램을 즉시 종료한다.
    assert(i >= 0);


    // 예외
    try {
        read_file("fake_file.dat");
    } catch (cannot_open_file& e) { // 파일을 열지 못했을 때
        std::cerr << "Cannot open file.....\n";

        // 잡은 오류를 그대로 던질 수도 있다.
        // throw e;
        // throw;

        std::exit(EXIT_FAILURE);
    } catch (...) { // 다른 모든 예외들을 처리한다.
        // ...
    }

    bool keep_trying = true;

    // 다음과 같이 응용 가능하다.
    do {
        char fname[80];
        std::cout << "Please enter your file name : ";
        std::cin >> fname;

        try {
            read_file(fname);

            // ...

            keep_trying = false;
        } catch (cannot_open_file& e) {
            std::cerr << "Cannot opened file..\n";
        } catch (...) {
            std::cerr << "Try another file!!\n";
        }

    } while (keep_trying);


    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <cmath>

void write_something(std::ostream& os){
    os << "Hi stream, did you know that 3 * 3 = " << 3 * 3 << std::endl;
}

void with_io_exceptions(std::ios& io){
    io.exceptions(std::ios_base::badbit | std::ios_base::failbit);
}

int main(int argc, char * argv[]){
    int x = 5, age, width, height;

    std::cout << "Then square root of " << x << " is " << sqrt(x) << std::endl;

    // 삽입 연산자는 우선순위가 상대적으로 낮으므로 산술 연산을 직접 작성할 수 있다.
    std::cout << "11 * 19 = " << 11 * 19 << std::endl;

    std::cout << "Input your age : ";
    // 표준 입력 사용법
    std::cin >> age;

    // 비교, 논리, 비트 연산, 조건부 연산자는 괄호로 둘러싸서 그룹으로 만들어준다.
    std::cout << (age > 65 ? "I'm a wise guy\n" : "I am still half-baked.\n");

    std::cout << "Input width and height : ";
    // std::cin >> width >> height;
    // 위 구문은 아래 구문과 같다.
    std::cin >> width;
    std::cin >> height;

    std::cout << "width is " << width << " & height is " << height << std::endl;

    // 파일 입출력은 파일 스트림을 통해 cin, cout 과 같은 방식으로 사용할 수 있다.
    std::ofstream square_file;
    square_file.open("squares.txt");

    // 또한 다음과 같이 암시적으로 열 수 있다.
    // std::ofstream square_file("squares.txt");
    
    for(int i = 0 ; i < 10 ; i ++)
        square_file << i << "^2 = " << i * i << std::endl;
    
    // RAII 문법 덕분에 close를 하지 않아도 스코프를 벗어날 때 암시적으로 닫는다.
    // square_file.close();


    // 스트림 응용

    std::ofstream myfile("example.txt");
    std::stringstream mysstream;

    write_something(std::cout);
    write_something(myfile);
    write_something(mysstream);

    std::cout << "mysstream is " << mysstream.str();


    // 서식 지정
    double pi = M_PI;
    
    // 원본
    std::cout << "pi is " << pi << '\n';
    
    // 부동소수점 출력 정밀도 높이기
    std::cout << "pi is " << std::setprecision(16) << pi << '\n';

    // 출력의 너비 설정하기
    std::cout << "pi is " << std::setw(30) << pi << '\n';

    // 왼쪽 정렬 + 문자 채우기 + 너비 설정
    std::cout << "pi is " << std::setfill('-') << std::left << std::setw(30) << pi << '\n';

    // 또는 플래그를 지정한다.
    std::cout.setf(std::ios_base::showpos);
    std::cout << "pi is " << std::scientific << pi << '\n';

    // 진수 출력은 다음과 같이 할 수 있다.
    std::cout << "63 octal is " << std::oct << 63 << '\n';
    std::cout << "63 hexadecimal is " << std::hex << 63 << '\n';
    std::cout << "63 decimal is " << std::dec << 63 << '\n';

    // bool 값은 0, 1 출력이지만 true와 false로 표시할 수 있다.mysstream
    std::cout << "pi < 3 is " << (pi < 3) << '\n';
    std::cout << "pi < 3 is " << std::boolalpha << (pi < 3) << '\n';

    // 옵션 재설정은 다음과 같이 할 수 있다.
    int old_pricision = std::cout.precision();

    std::cout << std::setprecision(16);

    std::cout.unsetf(std::ios_base::adjustfield | std::ios_base::basefield
        | std::ios_base::floatfield | std::ios_base::showpos | std::ios_base::boolalpha);
    std::cout.precision(old_pricision);


    // C++ IO 에서의 스트림은 기본적으로 예외를 발생시키지 않는다.
    // good() 을 사용하여 판별한다.

    std::ifstream infile;
    std::string filename("some_missing_file.xyz");
    bool opened = false;

    while(!opened){
        infile.open(filename);
        if(infile.good()){
            opened = true;
        }else{
            std::cout << "The file '" << filename << "' doesn't exist.\n"
                << "Give a new file name : ";
            std::cin >> filename;
        }
    }

    int i;
    double d;

    infile >> i >> d;
    if(infile.good()){
        std::cout << "i is " << i << ", d is " << d << '\n';
    }else{
        std::cout << "Could not correctly read the content.\n";
    }
    infile.close();

    // 또한 다음과 같이 플래그를 줘서 예외가 발생하도록 할 수 있다.
    std::cout.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);


    // 다음은 분명히 잘못된 프로그램임에도 불구하고 io는 정확성을 검증하지 못한다.

    std::ofstream outfile;
    with_io_exceptions(outfile);
    outfile.open("f.txt");

    double o1 = 5.2, o2 = 6.2;
    outfile << o1 << o2 << std::endl;

    outfile.close();

    std::ifstream infile2;
    with_io_exceptions(infile2);
    infile2.open("f.txt");

    int i1, i2;
    char c;
    infile2 >> i1 >> c >> i2;

    std::cout << "i1 = " << i1 << ", i2 = " << i2 << '\n';


    return 0;
}
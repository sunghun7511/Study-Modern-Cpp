#include <iostream>
#include <fstream>
#include <iosfwd>
#include <cmath>

void write_something(std::ostream& os){
    os << "Hi stream, did you know that 3 * 3 = " << 3 * 3 << std::endl;
}

int main(int argc, char * argv[]){
    int x = 5, age, width, height;

    std::cout << "Then square root of " << x << " is " << sqrt(x) << std::endl;

    // 삽입 연산자는 우선순위가 상대적으로 낮으므로 산술 연산을 직접 작성할 수 있다.
    std::cout << "11 * 19 = " << 11 * 19 << std::endl;

    // 표준 입력 사용법
    std::cin >> age;

    // 비교, 논리, 비트 연산, 조건부 연산자는 괄호로 둘러싸서 그룹으로 만들어준다.
    std::cout << (age > 65 ? "I'm a wise guy\n" : "I am still half-baked.\n");

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


    std::ofstream myfile("example.txt");

    write_something(std::cout);
    write_something(myfile);

    // ?? std::stringstream 이 안먹힌다.
    // ./io.cpp:46:23: error: aggregate ‘std::stringstream mysstream’ has incomplete type and cannot be defined
    //  std::stringstream mysstream;


    return 0;
}
// main.cpp

#include <iostream>
#include "example.h"

int main() {
    ExampleClass example;
    example.setNumber(42);
    std::cout << "Number from C++: " << example.getNumber() << std::endl;
    return 0;
}

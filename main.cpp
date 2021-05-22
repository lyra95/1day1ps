#include <iostream>
#include "solution.cpp"

int main()
{
    std::cout << "test started" << std::endl; 
    Test t;
    t.push({{6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0}}, 3);
    t.test();
    std::cout << "test completed" << std::endl;
    return 0;
}
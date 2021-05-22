#include <iostream>
#include "solution.cpp"

int main()
{

    std::cout << (-1)%2 << std::endl;
    std::cout << "test started" << std::endl; 
    Test t;
    t.push({vector<int>{500,600,150,800,2500}}, 3100);
    t.push({vector<int>{1000,100,500,600,150,800,2500}}, 3200);
    t.push({vector<int>{100,1000,500,600,150,800,2500}}, 4100);
    t.test();
    std::cout << "test completed" << std::endl;
    cout << solution({ 1, 2, 3, 1 }) << " " <<  4 << endl;
    cout << solution({ 1, 1, 4, 1, 4 })<< " "<<  8 << endl;
    cout << solution({ 1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000 }) << " " << 3000 << endl;
    cout << solution({ 1000, 1, 0, 1, 2, 1000, 0 }) << " " << 2001 << endl;
    cout << solution({ 1000, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 1000 }) << " " << 2000 << endl;
    cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) << " " << 30 << endl;
    cout << solution({ 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 1, 1 }) << " " << 201 << endl;
    cout << solution({ 11, 0, 2, 5, 100, 100, 85, 1 }) << " " << 198 << endl;
    cout << solution({ 1, 2, 3 }) <<" " << 3 << endl;
    cout << solution({ 91, 90, 5, 7, 5, 7 }) << " " << 104 << endl;
    cout << solution({ 90, 0, 0, 95, 1, 1 }) << " " << 185 << endl;
    return 0;
}
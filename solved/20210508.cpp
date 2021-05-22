// 20210508
// programmers
// level4
// 도둑질
// https://programmers.co.kr/learn/courses/30/lessons/42897
// test
// #include <iostream>
// #include "solution.cpp"
// 
// int main()
// {
// 
//     std::cout << (-1)%2 << std::endl;
//     std::cout << "test started" << std::endl; 
//     Test t;
//     t.push({vector<int>{500,600,150,800,2500}}, 3100);
//     t.push({vector<int>{1000,100,500,600,150,800,2500}}, 3200);
//     t.push({vector<int>{100,1000,500,600,150,800,2500}}, 4100);
//     t.test();
//     std::cout << "test completed" << std::endl;
//     cout << solution({ 1, 2, 3, 1 }) << " " <<  4 << endl;
//     cout << solution({ 1, 1, 4, 1, 4 })<< " "<<  8 << endl;
//     cout << solution({ 1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000 }) << " " << 3000 << endl;
//     cout << solution({ 1000, 1, 0, 1, 2, 1000, 0 }) << " " << 2001 << endl;
//     cout << solution({ 1000, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 1000 }) << " " << 2000 << endl;
//     cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) << " " << 30 << endl;
//     cout << solution({ 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 1, 1 }) << " " << 201 << endl;
//     cout << solution({ 11, 0, 2, 5, 100, 100, 85, 1 }) << " " << 198 << endl;
//     cout << solution({ 1, 2, 3 }) <<" " << 3 << endl;
//     cout << solution({ 91, 90, 5, 7, 5, 7 }) << " " << 104 << endl;
//     cout << solution({ 90, 0, 0, 95, 1, 1 }) << " " << 185 << endl;
//     return 0;
// }
// solution
#include <string>
#include <vector>

using namespace std;

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int solution(vector<int> money) {
    auto N = money.size();
    int ds[N][2][2];
    ds[0][false][false] = 0;
    ds[0][false][true] = 0;
    ds[0][true][false] = 0;
    ds[0][true][true] = money[0];

    decltype(N) pos = 1;
    for(;pos<N-1;++pos)
    {
        ds[pos][false][false] = max( ds[pos-1][false][true], ds[pos-1][false][false] );
        ds[pos][false][true] = money[pos] + ds[pos-1][false][false];
        ds[pos][true][false] = max( ds[pos-1][true][true], ds[pos-1][true][false] );
        ds[pos][true][true] = money[pos] + ds[pos-1][true][false];
    }

    int first = ds[pos][false][true] = money[pos] + ds[pos-1][false][false];
    int second = ds[pos][true][false] = max( ds[pos-1][true][true], ds[pos-1][true][false] );

    return max(first, second);
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<int> money;
    };

    private:
    vector<TestInput> test_cases;
    vector<answerType> answers;
    
    public:
    void push(TestInput t, answerType a)
    {
        test_cases.push_back(t);
        answers.push_back(a);
    }
    void test()
    {   
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].money    );
            try
            {
                if(ans == answers[i])
                {
                    std::cout << "succeeded " << i+1 << "th case" << std::endl;
                    count++;
                }
                else
                {
                    std::cout << "failed "<< i+1 << "th case, ans=" << answers[i] << " given=" << ans << std::endl;
                }

            }
            catch(...)
            {
                std::cout << "failed "<< i+1 << "th case, runtime error!" << std::endl;
            }
        }
        std::cout << "passed total " << count << " cases over " << test_cases.size() << " cases." << std::endl;
    }
};


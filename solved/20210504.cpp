// 20210504
// programmers
// level3
// 정수삼각형
// https://programmers.co.kr/learn/courses/30/lessons/43105

#include <vector>
#include <iostream>
using namespace std;
// solution
int solution(vector<vector<int>> triangle) {
    vector<vector<int>> copy=triangle;
    for(int level=1;level<triangle.size();level++)
    {
        int i = 0;
        copy[level][i] += copy[level-1][i];
        for(i=1;i+1<copy[level].size();i++)
        {
            int l = copy[level-1][i-1];
            int r = copy[level-1][i];
            (l>r) ? copy[level][i] += l : copy[level][i] += r;
        }
        copy[level][i] += copy[level-1][i-1];
    }
    
    int ans = copy.back()[0];
    for(int i=1;i<copy.back().size();i++)
        if(copy.back()[i] > ans) ans = copy.back()[i];    
    return ans;
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<vector<int>> triangle;
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
    void helper()
    {
        {
            vector<vector<int>> triangle{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
            TestInput t{triangle};
            int ans = 30;
            push(t,ans);
        }
    }
    void test()
    {   
        helper();
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].triangle    );
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


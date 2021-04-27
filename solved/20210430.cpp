// 20210430
// programmers
// level2
// 가장큰수
// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
// solution
string solution(vector<int> numbers) {
    vector<string> numbers_{};
    for(int n:numbers)
        numbers_.push_back(to_string(n));
    auto comp = [](string a, string b){
        return a+b > b+a;
    };
    sort(numbers_.begin(),numbers_.end(), comp);
    string answer = "";
    for(auto x:numbers_)
        answer += x;
    return (answer[0]!='0') ? answer:"0";
}

typedef string answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<int> numbers;
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
        // [6, 10, 2] 	"6210"
        {   
            vector<int> numbers{6, 10, 2};
            TestInput t{numbers};
            string ans = "6210";
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
            answerType ans = solution( test_cases[i].numbers );
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


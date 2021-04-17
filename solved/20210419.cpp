// 20210419
// programmers
// level2
// 전화번호목록
// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// solution
typedef bool answerType;
using namespace std;
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    for(int i=1;i<phone_book.size();i++)
    {
        if(phone_book[i-1] == phone_book[i].substr(0,phone_book[i-1].size()))
            return false;
    }
    return true;
}

// test
class Test
{
    public: struct TestInput
    {
        vector<string> phone_book;
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
    void helpher()
    {
        vector<string> pb{"119", "97674223", "1195524421"};
        TestInput t{pb};
        bool ans=false;
        push(t,ans);

        vector<string> pb2{"123","456","789"};
        TestInput t2{pb2};
        bool ans2=true;
        push(t2,ans2);

        vector<string> pb3{"12","123","1235","567","88"};
        TestInput t3{pb3};
        bool ans3=false;
        push(t3,ans3);
    }    
    void test()
    {   
        helpher();
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution( test_cases[i].phone_book );
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


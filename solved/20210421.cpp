// 20210421
// programmers
// level2
// 조이스틱
// https://programmers.co.kr/learn/courses/30/lessons/42860

#include <vector>
#include <iostream>
using namespace std;
// solution
typedef int answerType;

int min(int a,int b)
{
    return (a>b) ? b:a;
}
int UpDown(char x)
{
    int foward = x-'A';
    int backward = 'Z'-x+1;
    return (foward > backward) ? backward : foward;
}

int solution(string name) {
    int answer=0;
    for(int pos=0;pos<name.size();pos++)
    {
        answer += UpDown(name[pos]);
    }
    
    int forward = 0;
    int backward = name.size()-1;
    int third=0;
    for(int pos=0;pos<name.size();pos++)
    {
        if(name[pos]!='A')
        {
            forward = pos;
        }
    }
    for(int pos=name.size();pos>0;pos--)
    {
        if(name[pos]!='A')
        {
            backward = pos;
        }
    }
    backward = name.size()-backward;
    for(int pos=0;2*pos<name.size();pos++)
    {
        if(name[pos]!='A')
        {
            third = pos;
        }
    }
    third = 2*third;
    int temp;
    for(int pos=name.size();pos>=name.size()/2;pos--)
    {
        if(name[pos]!='A')
        {
            temp = pos;
        }
    }
    third += name.size()-temp;
    return answer+min(forward,min(backward,third));
}

// test
class Test
{
    public: struct TestInput
    {
        string name;
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
        push(TestInput{"JEROEN"},56);
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].name    );
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


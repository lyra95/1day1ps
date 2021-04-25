// 20210426
// programmers
// level3
// N으로표현
// https://programmers.co.kr/learn/courses/30/lessons/42895

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
// solution
typedef int answerType;
void helper(unordered_map<int,int> & table, int key, int newVal)
{
    if(newVal>8) return;
    if(key<0) key=-key;
    auto iter = table.find(key);
    if(iter!=table.end())
    {
        if(newVal < table[key]) 
            iter->second=newVal;
    } else
    {
        table[key]=newVal;
    }
}
unordered_map<int,int> update(unordered_map<int,int> & table)
{
    unordered_map<int,int> newTable = table;
    for(auto p:table)
    {
        for(auto q:table)
        {
            int k1 = p.first;
            int k2 = q.first;
            int v1 = p.second;
            int v2 = q.second;
            int newVal = v1+v2;
            helper(newTable, k1+k2, newVal);
            helper(newTable, k1-k2, newVal);
            helper(newTable, k1*k2, newVal);
            if(k2!=0) helper(newTable, k1/k2, newVal);
            if(k1!=0) helper(newTable, k2/k1, newVal);
        } 
    }
    return newTable;
}
answerType solution( int N, int number )
{
    unordered_map<int, int> table;
    int x=0;
    for(int i=0;i<=7;i++)
    {
        table[x] = i;
        x = x*10+N;
    }
    for(int i=0;i<10;i++)
    {
        table = update(table);
    }

    auto iter = table.find(number);
    if(iter!=table.end())
    {
        int ans = iter->second;
        return (ans > 8) ? -1:ans;
    } else
        return -1;
}

// test
class Test
{
    public: struct TestInput
    {
        int N;
        int number;
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
    void helper2(int a,int b, int c)
    {
        TestInput t{a,b};
        int ans = c;
        push(t,ans);        
    }
    void helper()
    {
        helper2(5,12,4);
        helper2(2,11,3);
        helper2(5,5,1);
        helper2(5,10,2);
        helper2(5,31168,-1);
        helper2(1,1121,7);
        helper2(5,1010,7);
        helper2(3,4,3);
        helper2(5,5555,4);
        helper2(5,5550,5);
        helper2(5,20,3);
        helper2(5,30,3);
        helper2(6,65,4);
        helper2(5,2,3);
        helper2(5,4,3);
        helper2(1,1,1);
        helper2(1,11,2);
        helper2(1,111,3);
        helper2(1,1111,4);
        helper2(1,11111,5);
        helper2(7,7776,6);
        helper2(7,7784,5);
        helper2(2,22222,5);
        helper2(2,22223,7);
        helper2(2,22224,6);
        helper2(2,11111,6);
        helper2(2,11,3);
        helper2(2,111,4);
        helper2(2,1111,5);
        helper2(9,36,4);
        helper2(9,37,6);
        helper2(9,72,3);
        helper2(3,18,3);
        helper2(2,1,2);
        helper2(4,17,4);
    }
    void test()
    {   
        helper2(5,23,5);
        helper2(5,27,5);
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].N, test_cases[i].number     );
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


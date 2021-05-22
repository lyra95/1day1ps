// 20210507
// programmers
// level3
// 베스트앨범
// https://programmers.co.kr/learn/courses/30/lessons/42579
// test
// t.push({vector<string>{"classic", "pop", "classic", "classic", "pop"}, vector<int>{500,600,150,800,2500}}, vector<int>{4,1,3,0});
// solution
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct genre_info
{
    string genre;
    vector<int> songs;
    int total;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string,genre_info> map{};
    for(int i=0;i<genres.size();i++)
    {
        map[genres[i]].songs.push_back(i);
    }

    auto sumAll = [&plays](vector<int> alist){
        int sum = 0;
        for(auto n : alist)
            sum += plays[n];
        return sum;
    };

    for(auto& iter:map)
    {
        iter.second.genre = iter.first;
        sort(iter.second.songs.begin(),iter.second.songs.end(),
            [&plays](auto a, auto b){ return plays[a] > plays[b]; }
        );
        iter.second.total = sumAll(iter.second.songs);
    }
    
    vector<genre_info> g(map.size());

    for(auto& iter:map)
    {
        g.push_back(iter.second);
    }

    sort(g.begin(),g.end(),
        [](auto a, auto b){ return a.total > b.total; }
    );

    vector<int> answer;

    for(auto& x:g)
    {
        int count = 0;
        while(count < 2 && count < x.songs.size())
        {
            answer.push_back(x.songs[count]);
            count++;
        }
    }

    return answer;
}

typedef vector<int> answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<string> genres;
        vector<int> plays;
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
            answerType ans = solution(  test_cases[i].genres, test_cases[i].plays    );
            try
            {
                if(ans == answers[i])
                {
                    std::cout << "succeeded " << i+1 << "th case" << std::endl;
                    count++;
                }
                else
                {
                    // std::cout << "failed "<< i+1 << "th case, ans=" << answers[i] << " given=" << ans << std::endl;
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


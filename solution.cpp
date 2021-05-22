// 20210509
// programmers
// level5
// 방의개수
// https://programmers.co.kr/learn/courses/30/lessons/49190?language=cpp
// test
// t.push({{6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0}}, 3);
// solution
#include <vector>
#include <array>
#include <map>
using namespace std;

vector<vector<int>> convert = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

class Plane
{
public:
    Plane()
    {
        get()[8] = true;
    }
    ~Plane() = default;

    array<bool,9>& get(int x, int y)
    {
        return plane[pos{x,y}];
    }
    array<bool,9>& get()
    {
        return plane[pos{current_x,current_y}];
    }

    bool new_area(int dir)
    {
        return get()[8] && !get()[dir];
    }

    void move(int dir)
    {
        get()[dir] = true;
        int x = convert[dir][0];
        int y = convert[dir][1];
        current_x += x;
        current_y += y;

        auto opposite = (dir+4)%8;
        if(new_area(opposite))
            num_areas++;
        get()[8] = true;
        get()[opposite] = true;
        get()[dir] = true;

        current_x += x;
        current_y += y;
        if(new_area(opposite))
            num_areas++;
        get()[8] = true;
        get()[opposite] = true;
    }

    int move(vector<int> arrows)
    {
        for(auto dir:arrows)
            move(dir);
        return num_areas;
    }
private:
    struct pos
    {
        int x;
        int y;
        bool operator < (const pos& b) const
        {
            return (x > b.x) ? true : (x == b.x) ? y > b.y : false;
        }
    };
    
    map<pos,array<bool,9>> plane;
    int current_x = 0;
    int current_y = 0;
    int num_areas = 0;
};


int solution(vector<int> arrows) {
    Plane p{};
    int answer = p.move(arrows);
    
    return answer;
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<int> arrows;
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
            answerType ans = solution(  test_cases[i].arrows   );
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

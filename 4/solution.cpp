#include <string>
#include <vector>

using namespace std;
enum class state{
    gray,
    white,
    black
};


struct Node{
    state s;
    int depth;
    Node *childs[4];
};

Node* make(string S, int depth, int& head)
{
    if(head >= S.size())
        return nullptr;
    else if(S[head] == 'b')
    {   
        head++;
        return new Node{state::black, depth, nullptr};
    }
    else if(S[head] == 'w')
    {
        head++;
        return new Node{state::white, depth, nullptr};
    }
    else
    {
        Node *ans = new Node{state::gray, depth, nullptr};
        head += 1;
        for(int i = 0;i<4;i++)
        {
            ans->childs[i] = make(S, depth + 1,head);
        }
        return ans;
    }
    return {};
}

int num_blacks(Node* node)
{
    if(node==nullptr)
        return 0;
    else if(node->s == state::black)
    {
        int answer = 1024;
        for(int i=0;i<node->depth;i++)
        {
            answer /= 4;
        }

        return answer;
    }
    else if(node->s == state::white)
    {
        return 0;
    }
    else
    {
        int answer = 0;
        for(int i=0;i<4;i++)
        {
            answer += num_blacks(node->childs[i]);
        }
        return answer;
    }
    return 0;
}

// tree:node2 is added to tree:node1
Node* add(Node* node1, Node* node2)
{
    if(node1 == nullptr && node2 == nullptr)
        return nullptr;
    else if(node1 == nullptr)
        return node2;
    else if(node2 == nullptr)
        return node1;
    else if(node1->s == state::black)
        return node1;
    else if(node2->s == state::black)
        return node2;
    else if(node1->s == state::white)
        return node2;
    else if(node2->s == state::white)
        return node1;
    else
    {
        Node* ans = new Node{state::gray,node1->depth,nullptr};
        for(int i=0; i<4;i++)
        {
            ans->childs[i] = add(node1->childs[i],node2->childs[i]);
        }
        return ans;
    }
}

int solution(string S1, string S2) {
    int head1 = 0;
    Node* tree1 = make(S1, 0, head1);
    int head2 = 0;
    Node* tree2 = make(S2, 0, head2);

    Node* tree3 = add(tree1, tree2);
    return num_blacks(tree3);
}
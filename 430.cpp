// 430. 扁平化多级双向链表
// 多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

// 给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*nowPosition=head;
        vector<Node*> nodeList;
        if(head!=nullptr)
            nodeList.push_back(nowPosition);
        else
            return head;
        // cout<<"test";
        vector<Node*> res;
        // cout<<nodeList.size();
        while(!nodeList.empty())
        {
            nowPosition=nodeList[nodeList.size()-1];
            // cout<<nowPosition->val<<endl;
            nodeList.pop_back();
            res.push_back(nowPosition);
            if(nowPosition->next!=nullptr)
            {
                nodeList.push_back(nowPosition->next);
                // nowPosition->next=nullptr;
            }
            if(nowPosition->child!=nullptr)
            {
                nodeList.push_back(nowPosition->child);
                // nowPosition->next=nullptr;
            }
        }
        // cout<<nodeList.size();
        // cout<<res.size();
        for(int i=0;i<res.size()-1;++i)
        {
            // cout<<" "<<i<<" "<<res.size()<<" "<<res.size()-1<<endl;
            res[i]->next=res[i+1];
            res[i+1]->prev=res[i];
            res[i]->child=nullptr;
            // cout<<res[i]->val<<endl;
        }
        // cout<<res.size();
        // if(!res.empty())
        // {
        res[res.size()-1]->next=nullptr;
        res[res.size()-1]->child=nullptr;
        return res[0];
        // }
        // else
        //     return head;
    }
};
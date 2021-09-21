// 725. 分隔链表
// 给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。

// 每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。

// 这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。

// 返回一个符合上述规则的链表的列表。

// 举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sum(0);
        ListNode* tempNode=head;
        while(tempNode!=nullptr)
        {
            sum+=1;
            tempNode=tempNode->next;
        }
        int aver=sum/k;
        int left=sum%k;
        vector<ListNode*>res;
        tempNode=head;
        for(int i=0;i<k;++i)
        {
            // tempRes=tempNode;
            int tempNum=aver;
            if(left>0)
            {
                ++tempNum;
                --left;
            }    
            // cout<<tempNum<<endl;
            if(tempNum==0)
            {
                res.push_back(nullptr);
            }
            else
            {
                res.push_back(tempNode);
                for(int j=0;j<tempNum-1;++j)
                {
                    tempNode=tempNode->next;
                }
                ListNode* tempNode1=tempNode;
                tempNode=tempNode->next;
                tempNode1->next=nullptr;
            }
            
        }
        return res;
    }
};
352. 将数据流变为多个不相交区间
 给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。

实现 SummaryRanges 类：

SummaryRanges() 使用一个空数据流初始化对象。
void addNum(int val) 向数据流中加入整数 val 。
int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。

struct Node
{
    int left;
    int right;
    Node*prev;
    Node*next;
    Node()
    {
        prev=NULL;
        next=NULL;
    }
    Node(int left,int right)
    {
        this->left=left;
        this->right=right;
        prev=NULL;
        next=NULL;
    }
};
class SummaryRanges {
public:

    Node* data;
    int size;
    SummaryRanges() {
        data=NULL;
        size=0;
    }
    
    void addNum(int val) {
        if(size==0)
        {
            data=new Node(val,val);
            size=1;
        }
        else
        {
            Node*head=data;
            while(true)
            {
                // cout<<val<<" "<<head->left<<" "<<head->right<<endl;
                if(head->left>val)
                {
                    if(head->left-1==val)
                        head->left=val;
                    else
                    {
                        Node*temp=new Node(val,val);
                        if(head!=data)
                        {
                            head->prev->next=temp;
                            temp->prev=head->prev;
                            head->prev=temp;
                            temp->next=head;
                        }
                        else
                        {
                            head->prev=temp;
                            temp->next=head;
                            data=temp;
                        }
                        
                        ++size;
                    }
                    break;
                }
                else if(head->right<val)
                {
                    if(head->right+1==val)
                    {
                        if(head->next!=NULL)
                        {
                            if(head->next->left-1==val)
                            {
                                head->right=head->next->right;
                                if(head->next->next!=NULL)
                                {
                                    head->next->next->prev=head;
                                    head->next=head->next->next;
                                }
                                else
                                    head->next=NULL;
                                --size;
                            }
                            else
                            {
                                head->right=val;
                            }
                        }
                        else
                        {
                            head->right=val;
                        }
                        break;
                    }
                    else
                    {
                        if(head->next!=NULL)
                            head=head->next;
                        else
                        {
                            Node*temp=new Node(val,val);
                            head->next=temp;
                            temp->prev=head;
                            ++size;
                            break;
                        }
                    }
                }
                else
                    break;
            }
        }
            
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        Node*head=data;
        for(int i=0;i<size;++i)
        {
            // cout<<head->left<<" "<<head->right<<endl;
            res.push_back({head->left,head->right});
            head=head->next;
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
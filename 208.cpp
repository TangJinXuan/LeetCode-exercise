208. 实现 Trie (前缀树)
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

class Trie {
private:
    Trie* charNext[26];
    bool isEnd;
public:
    Trie() {
        for(auto i=0;i<26;++i)
            charNext[i]=NULL;
        this->isEnd=false;
    }
    
    void insert(string word) {
        Trie*head=this;
        for(auto i:word)
        {
            int thisChar=i-'a';
            if(head->charNext[thisChar]==NULL)
            {
                head->charNext[thisChar]=new Trie();
            }
            head=head->charNext[thisChar];
        }
        head->isEnd=true;
    }
    
    bool search(string word) {
        Trie*head=this;
        for(auto i:word)
        {
            int thisChar=i-'a';
            if(head->charNext[thisChar]==NULL)
            {
                return false;
            }
            else
                head=head->charNext[thisChar];
        }
        if(head->isEnd)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        Trie*head=this;
        for(auto i:prefix)
        {
            int thisChar=i-'a';
            if(head->charNext[thisChar]==NULL)
            {
                return false;
            }
            else
                head=head->charNext[thisChar];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
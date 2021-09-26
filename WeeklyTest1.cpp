给你一个 m x n 的矩阵 board ，它代表一个填字游戏 当前 的状态。填字游戏格子中包含小写英文字母（已填入的单词），表示 空 格的 ' ' 和表示 障碍 格子的 '#' 。

如果满足以下条件，那么我们可以 水平 （从左到右 或者 从右到左）或 竖直 （从上到下 或者 从下到上）填入一个单词：

该单词不占据任何 '#' 对应的格子。
每个字母对应的格子要么是 ' ' （空格）要么与 board 中已有字母 匹配 。
如果单词是 水平 放置的，那么该单词左边和右边 相邻 格子不能为 ' ' 或小写英文字母。
如果单词是 竖直 放置的，那么该单词上边和下边 相邻 格子不能为 ' ' 或小写英文字母。
给你一个字符串 word ，如果 word 可以被放入 board 中，请你返回 true ，否则请返回 false 。
class Solution {
public:
    template <typename T>
    vector<vector<T>> rot2d(vector<vector<T>> a, int clockwise = 1) {
        if(a.empty()) return a;
        int n = a.size(), m = a[0].size();
        assert(m > 0);
        vector<vector<T>> ret(m, vector<T>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                ret[j][i] = clockwise ? a[n - 1 - i][j] : a[i][m - 1 - j];
            }
        }
        return ret;
    }
    int solve(vector<char> a, string s) {
        int n = a.size(), m = s.size();
        int lst = -1;
        for(int i = 0; i <= n; ++i) {
            if(i == n || a[i] == '#') {
                if(i - lst - 1 == m) {
                    int ok = 1;
                    for(int j = lst + 1, k = 0; j < i; ++j, ++k) {
                        if(a[j] != ' ' && a[j] != s[k]) {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok) return 1;
                }
                lst = i;
            }
        }
        return 0;
    }
    bool placeWordInCrossword(vector<vector<char>>& a, string s) {
        int n = a.size(), m = a[0].size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        for(int i = 0; i < n; ++i) {
            if(solve(a[i], s) || solve(a[i], rs)) return 1;
        }
        a = rot2d(a);
        assert(a.size() == m);
        for(int i = 0; i < m; ++i) {
            if(solve(a[i], s) || solve(a[i], rs)) return 1;
        }
        return 0;
    }
};
class Solution {
public:
    struct exptree {
        typedef long long ll;
        static const int maxn = 1005;
        int priority[128];
        struct node {
            ll val; int pos; char op;
            int ls, rs;
        }a[maxn]; // exptree
        int tot = 0, rt;
        ll val[maxn]; char op[maxn]; int stk[maxn], pos[maxn], tp = 0; // stack
        exptree() {
            pos[0] = -1;
            // set priority
            priority['|'] = 1;
            priority['^'] = 2;
            priority['&'] = 3;
            priority['+'] = priority['-'] = 4;
            priority['*'] = priority['/'] = 5;
        }
        ll calc(ll x, ll y, char o) {
            if(o == '+') return x + y;
            if(o == '*') return x * y;
            if(o == '-') return x - y;
            if(o == '/') return x / y;
            if(o == '&') return x & y;
            if(o == '|') return x | y;
            if(o == '^') return x ^ y;
            assert(0);
            return -1;
        }
        void build(string s) {
            ll cur = 0; tp = tot = 0;
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] >= '0' && s[i] <= '9') {
                    cur = cur * 10 + s[i] - '0';
                } else if(s[i] == '(') {
                    op[++tp] = '(';
                    pos[tp] = i;
                } else if(s[i] == ')') {
                    op[++tp] = ')';
                    pos[tp] = pos[tp-1];
                } else if(s[i] == ' ') {
                    // pass
                } else {
                    assert(priority[s[i]]);
                    int u = ++tot;
                    a[tot] = {cur, pos[tp]+1, 0, 0, 0}; cur = 0;
                    int cnt = 0;
                    if(op[tp] == ')') {
                        while(op[tp] == ')') --tp, ++cnt;
                        while(cnt) {
                            while(op[tp] != '(') {
                                assert(op[tp] != ')');
                                ++tot;
                                a[tot] = {calc(a[stk[tp]].val, a[u].val, op[tp]),
                                          pos[tp], op[tp], stk[tp], u};
                                u = tot;
                                --tp;
                            }
                            while(cnt && op[tp] == '(') --tp, --cnt;
                        }
                    }
                    assert(!cnt);
                    while(tp && priority[s[i]] <= priority[op[tp]]) {
                        ++tot;
                        a[tot] = {calc(a[stk[tp]].val, a[u].val, op[tp]),
                                  pos[tp], op[tp], stk[tp], u};
                        u = tot;
                        --tp;
                        while(cnt && op[tp] == '(') --tp, --cnt;
                    }
                    ++tp;
                    stk[tp] = u;
                    op[tp] = s[i];
                    pos[tp] = i;
                }
            }
            int u = ++tot;
            a[tot] = {cur, pos[tp]+1, 0, 0, 0}; cur = 0;
            int cnt = 0;
            if(op[tp] == ')') {
                while(op[tp] == ')') --tp, ++cnt;
                while(cnt) {
                    while(op[tp] != '(') {
                        assert(op[tp] != ')');
                        ++tot;
                        a[tot] = {calc(a[stk[tp]].val, a[u].val, op[tp]),
                                  pos[tp], op[tp], stk[tp], u};
                        u = tot;
                        --tp;
                    }
                    while(cnt && op[tp] == '(') --tp, --cnt;
                }
            }
            while(tp) {
                ++tot;
                a[tot] = {calc(a[stk[tp]].val, a[u].val, op[tp]),
                          pos[tp], op[tp], stk[tp], u};
                u = tot;
                --tp;
                while(cnt && op[tp] == '(') --tp, --cnt;
            }
            rt = u;
        }
    };
    vector<int> dp[32][32];
    int scoreOfStudents(string s, vector<int>& a) {
        function<vector<int>(int,int)> solve = [&](int l, int r) -> vector<int> {
            if(l == r) {
                return vector<int> {s[l] - '0'};
            }
            if(!dp[l][r].empty()) return dp[l][r];
            vector<int> ret;
            for(int i = l; i <= r; ++i) {
                if(s[i] == '+') {
                    auto a = solve(l, i - 1);
                    auto b = solve(i + 1, r);
                    for(int x : a) {
                        for(int y : b) {
                            if(x + y <= 1000) {
                                ret.push_back(x + y);
                            }
                        }
                    }
                } else if(s[i] == '*') {
                    auto a = solve(l, i - 1);
                    auto b = solve(i + 1, r);
                    for(int x : a) {
                        for(int y : b) {
                            if(x * y <= 1000) {
                                ret.push_back(x * y);
                            }
                        }
                    }
                }
            }
            sort(ret.begin(), ret.end());
            ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
            return dp[l][r] = ret;
        };
        exptree exp;
        exp.build(s);
        vector<int> score(1001);
        auto r = solve(0, s.size() - 1);
        for(int i : r) {
            score[i] = 2;
        }
        score[exp.a[exp.rt].val] = 5;
        int ret = 0;
        for(int i : a) ret += score[i];
        return ret;
    }
};
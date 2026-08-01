class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first;
        stack<char>second;

        for(int i=0; i<s.size(); i++){
            if(s[i] != '#')
                first.push(s[i]);
            else{
                if(first.empty())
                    continue;
                first.pop();
            }
        }
        for(int i=0; i<t.size(); i++){
            if(t[i] != '#')
                second.push(t[i]);
            else{
                if(second.empty())
                    continue;
                second.pop();
            }
        }

        if(first.size() != second.size())
            return 0;
        
        while(!first.empty()){
            if(first.top() == second.top()){
                first.pop();
                second.pop();
            }else{
                return 0;
            }
        }
        return first.empty();
    }
};
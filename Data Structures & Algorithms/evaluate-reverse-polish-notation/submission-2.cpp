class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            string ch = tokens[i];
            if(ch.length()==1 && !isdigit(ch[0])){
                int op2 = s.top(); s.pop();
                int op1 = s.top(); s.pop();
                if(ch=="+"){
                    s.push(op1+op2);
                }
                else if(ch=="-") s.push(op1-op2);
                else if(ch=="*") s.push(op1*op2);
                else if(ch=="/") s.push(op1/op2);
            }
            else s.push(stoi(ch)); //int would convert it to ascii value. so we need stoi
        }
        return s.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& S) {
        stack<long> s;
       for(int i = 0; i < S.size(); i++){
           
           if(S[i] == "+"){
               long t1 = s.top();
               s.pop();
               long t2 = s.top();
               s.pop();
               s.push(t1+t2);
           }
           else if(S[i] == "-"){
               long t1 = s.top();
               s.pop();
               long t2 = s.top();
               s.pop();
               s.push(t2-t1);
           }
           else if(S[i] == "*"){
               long t1 = s.top();
               s.pop();
               long t2 = s.top();
               s.pop();
               s.push(t2*t1);
           }
           else if(S[i] == "/"){
               long t1 = s.top();
               s.pop();
               long t2 = s.top();
               s.pop();
               s.push(t2/t1);
           }
           else{
               long a = stoi(S[i]);
               s.push(a);
           }
       }
       return s.top();
    }
};
//["-128","-128","*","-128","*","-128","*","8","*","-1","*"]
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string str = "";
        char carry = '0';
        for(int i = 0; i <= min(a.size(), b.size());i++){
            if(a[i] == '1' && b[i] == '1' && carry=='1'){
                str+="1";
                carry = '1';
            }
            else if(a[i] == '1' && b[i] == '1' && carry=='0'){
                str+="0";
                carry = '1';
            }
            else if(a[i] == '1' && b[i] == '0' && carry=='1'){
                str+="0";
                carry = '1';
            }
            else if(a[i] == '1' && b[i] == '0' && carry=='0'){
                str+="1";
                carry = '0';
            }
            else if(a[i] == '0' && b[i] == '1' && carry=='1'){
                str+="0";
                carry = '1';
            }
            else if(a[i] == '0' && b[i] == '1' && carry=='0'){
                str+="1";
                carry = '0';
            }
            else if(a[i] == '0' && b[i] == '0' && carry=='1'){
                str+="1";
                carry = '0';
            }
            else if(a[i] == '0' && b[i] == '0' && carry=='0'){
                str+="0";
                carry = '0';
            }
        }
        if(a.size() > b.size()){
            for(int i = b.size(); i < a.size(); i++){
                if(a[i] == '1' && carry == '1'){
                    str+="0";
                    carry='1';
                }
                else if(a[i] == '1' && carry == '0'){
                    str+="1";
                    carry='0';
                }
                else if(a[i] == '0' && carry == '1'){
                    str+="1";
                    carry='0';
                }
                else if(a[i] == '0' && carry == '0'){
                    str+="0";
                    carry='0';
                }
            }
        }
        else if(b.size() > a.size()){
            for(int i = a.size(); i < b.size(); i++){
                if(b[i] == '1' && carry == '1'){
                    str+="0";
                    carry='1';
                }
                else if(b[i] == '1' && carry == '0'){
                    str+="1";
                    carry='0';
                }
                else if(b[i] == '0' && carry == '1'){
                    str+="1";
                    carry='0';
                }
                else if(b[i] == '0' && carry == '0'){
                    str+="0";
                    carry='0';
                }
            }
        }
        if(carry == '1'){
            str+="1";
        }
        for(int i = str.size()-1; i >= 0; i--){
            if(str[i] == '0'){
                str[i] = '\0';
            }
            else{
                break;
            }
        }
        reverse(str.begin(), str.end());
        return str;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
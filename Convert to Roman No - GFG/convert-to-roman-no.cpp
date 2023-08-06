//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int n) {
        string str = "";
        while(n > 0)
        {
            if(n >= 1000){
                str += "M";
                n -= 1000;
            }
            else if(n >= 900 && n < 1000){
                str += "CM";
                n -= 900;
            }
            else if(n >= 500){
                str += "D";
                n -= 500;
            }
            else if(n >= 400 && n < 500){
                str += "CD";
                n -= 400;
            }
            else if(n >= 100){
                str += "C";
                n -= 100;
            }
            else if(n >= 90 && n < 100){
                str += "XC";
                n -= 90;
            }
            else if(n >= 50){
                str += "L";
                n -= 50;
            }
            else if(n >= 40 && n < 50){
                str += "XL";
                n -= 40;
            }
            else if(n >= 10){
                str += "X";
                n -= 10;
            }
            else if(n == 9 ){
                str += "IX";
                n -= 9;
            }
            else if(n >= 5)
            {
                str += "V";
                n -= 5;
            }
            else if(n == 4)
            {
                str += "IV";
                n -= 4;
            }
            else if(n >= 1)
            {
                str += "I";
                n -= 1;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}
// } Driver Code Ends
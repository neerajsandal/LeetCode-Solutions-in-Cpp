//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// CollegeCourse Class 
class CollegeCourse
{
    string courseId;
    char grade;
    int credits;
    int gradePoint;
    float honorPoint;
    
    public:
    void set_CourseId(string CID)
    {
        this->courseId = CID;
    }
    void set_Grade(char g){
        this->grade = g;
    }
    void set_Credit(int cr)
    {
        credits = cr;
    }
    int calculateGradePoints(char g)
    {
        g = toupper(g);
        if(g == 'A') return 10;
        else if(g == 'B') return 9;
        else if(g == 'C') return 8;
        else if(g == 'D') return 7;
        else if(g == 'E') return 6;
        else if(g == 'F') return 5;
    }
    
    float calculateHonorPoints(int gp,int cr)
    {
        honorPoint = gp*cr;
        return honorPoint;
    }
    void display()
    {
        int gp = calculateGradePoints(this->grade);
        cout << gp << " " << calculateHonorPoints(gp, this->credits) << endl;;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    CollegeCourse cc;
    string courseId;
    int gp;
    char grade;
    int credits;
    cin>>courseId>>grade>>credits;
    cc.set_CourseId(courseId);
    cc.set_Grade(grade);
    cc.set_Credit(credits);
    gp=cc.calculateGradePoints(grade);
    cc.calculateHonorPoints(gp,credits);
    cc.display();
    }
    return 0;
}

// } Driver Code Ends
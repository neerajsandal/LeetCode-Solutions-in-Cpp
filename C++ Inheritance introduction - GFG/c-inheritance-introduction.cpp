//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Cuboid 
{
    public:
    int length, width, height;
    
    void display()
    {
        cout << this->length << " " << this->width << " " << this->height << endl;
    }
};

class CuboidVol: public Cuboid
{
    public:
    void read_input(int l, int w, int h)
    {
        this->length = l;
        this->width = w;
        this->height = h;
    }
    void display()
    {
        cout << (this->length*this->width*this->height) << endl;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int l, w, h;
        cin>>l>>w>>h;
    
    // Declare a CuboidVol object
    
    CuboidVol c_vol;
    
    
    // Read length width and height
     
    c_vol.read_input(l,w,h);
    
    
    //  Print length, width and height
    
    c_vol.Cuboid::display();
    
    
    // Print the Volume
     
    c_vol.display();
    }
    
    return 0;
}
// } Driver Code Ends
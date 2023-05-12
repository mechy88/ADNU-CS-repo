/*
A solution to this problem: https://www.hackerrank.com/challenges/box-it/problem?isFullScreen=true
The challenge is to simply make a class that fits the needs of the main function, and behaves in a
way discribed in the challenge. The most challenging part of this challenge was debugging a problem
with my CalculateVolume method, as it returns an int instead of a long despite indicating I wanted a
long return type. The solution was before computing the volume, I needed to convert one of the variables
to a long, so that the final output is a long. Maybe it means that the data type of the variable with
the biggest range would be adopted as the data type of the final answer; I'll have to look into it more.
I also learned how to overload operators as member functions and non-member functions of the class.
*/

include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

class Box{
private:
    int l, b, h;
public:
    Box(){
        this->l = 0;
        this->b = 0;
        this->h = 0;
    }
    Box(int length, int breadth, int height){
        this->l = length;
        this->b = breadth;
        this->h = height;
    }
    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long CalculateVolume(){
        long length = l;
        return length*b*h;
    }
    bool operator<(Box& b){
        if(this->l < b.getLength())
            return true;
        else if((this->b < b.getBreadth()) && (this->l == b.getLength()))
            return true;
        else if((this->h < b.getHeight()) && (this->b == b.getBreadth()) && (this->l == b.getLength()))
            return true;
        return false;
    }
};

ostream& operator<<(ostream& out, Box& B){
        out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
        return out;
    }

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
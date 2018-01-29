#include <vector>
#include <iostream>
#include <time.h>

#include <string>
using namespace std;

//implement of algorithm
void LCS_recur(const string &str_a,const string &str_b,string &str_com,
				int & a_end,int & b_end) 
{
	if (a_end==-1 || b_end==-1)
	{
		return;
	}
	if (str_a[a_end] == str_b[b_end])
	{
		str_com.insert(str_com.begin(),str_a[a_end]);
		LCS_recur(str_a,str_b,str_com,--a_end,--b_end);	
	}
	else 
	{
		string str_com1(""),str_com2("");
		int a_end_1(a_end-1),b_end_1(b_end),a_end_2(a_end),b_end_2(b_end-1);
		LCS_recur(str_a,str_b,str_com1,a_end_1,b_end_1);
		LCS_recur(str_a,str_b,str_com2,a_end_2,b_end_2);
		
		str_com.insert(0,str_com1.size()>str_com2.size() ? str_com1:str_com2);
		cout << "common1 : " << str_com1 <<endl; 
		cout << "common2 : " << str_com2 <<endl;			
	}
	
}

int main(int argc, char** argv)
{	
 	if ( argc != 3 )
    {
        cout<<"please input two strings!"<<endl;
        return 1;
    }
	//variables use to compute the time of algorithm spend
	struct timespec tpstart;
    struct timespec tpend;	
    ////
    
    //data and variables input to algorithm
    string string_a(argv[1]);
    string string_b(argv[2]);    
    string string_com(""); 
    int str_a_end(string_a.size()-1);
    int str_b_end(string_b.size()-1);
    ////
    
    //run myalgorithm() and compute the time of that spend
    clock_gettime(CLOCK_REALTIME, &tpstart);
    
    LCS_recur(string_a,string_b,string_com,str_a_end,str_b_end);  //run myalgorithm() 
    
    clock_gettime(CLOCK_REALTIME, &tpend);
    ////
    
    //display the results
    double timedif = (tpend.tv_sec-tpstart.tv_sec)+(tpend.tv_nsec-tpstart.tv_nsec)/1000000000.0;
    printf("clock_gettime time: %.12f\n", timedif);
    
    cout << "The largest common set is : " << string_com <<endl;
			
	////
}



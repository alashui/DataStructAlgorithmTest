#include <vector>
#include <iostream>
#include <time.h>

#include <string>
using namespace std;

//implement of algorithm
void LCS_recur(const string &str_a,const string &str_b,string &str_com) 
{
	
	int array_com[str_a.size()+1][str_b.size()+1];
	
	struct table_result{int value ,coor_x,coor_y;};
	vector<table_result> tab_result_vec;
	
	for(int i=0;i<=str_a.size();i++)
	{
		for(int j=0;j<=str_b.size();j++)
		{
			if(i==0 || j==0)
				array_com[i][j]=0;
				
			else if(str_a[i-1]==str_b[j-1])
			{
				array_com[i][j]= array_com[i-1][j-1] +1;
				table_result tab_res;
				tab_res.value = array_com[i][j];
				tab_res.coor_x = i;
				tab_res.coor_y = j;
				tab_result_vec.push_back(tab_res);
			}
			else
			    array_com[i][j]= array_com[i-1][j] > array_com[i][j-1] ? 
			    				 array_com[i-1][j] : array_com[i][j-1];
			cout << array_com[i][j] <<' ';
		}
		cout << endl;
	}
	
	int min_value((tab_result_vec[0]).value);
	int max_value((tab_result_vec[tab_result_vec.size()-1]).value);
	if(min_value==0)
		cout <<"not find common set!" <<endl;
	else
	{
		for(int i==0;tab_result_vec[i]).value != min_value;i++)
		{
			int j(i);
			if ()
		}
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
    ////
    
    //run myalgorithm() and compute the time of that spend
    clock_gettime(CLOCK_REALTIME, &tpstart);
    
    LCS_recur(string_a,string_b,string_com);  //run myalgorithm() 
    
    clock_gettime(CLOCK_REALTIME, &tpend);
    ////
    
    //display the results
    double timedif = (tpend.tv_sec-tpstart.tv_sec)+(tpend.tv_nsec-tpstart.tv_nsec)/1000000000.0;
    printf("clock_gettime time: %.12f\n", timedif);
    
    cout << "The largest common set is : " << string_com <<endl;
			
	////
}



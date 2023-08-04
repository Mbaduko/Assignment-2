#include <iostream>
using namespace std;
int row_col,Sum_row,Sum_col,Sum_diagonal; //Essential variables
//function for checking if rows/cols are odd
bool check_odd(int a)  
{
	if(a%2==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
 {
	cout<<"\t\t\t\tHello!\n";
	cout<<"\t\t\t\t------\n\n";
	cout<<"\tYou're going to inter matrix and i'll tell you if is a square magic matrix or not\n\n\n\b";
 	cout<<"\tEnter number of rows as well as cols\n";
	Retry:    //label for retrying when rows not odd
 	cout<<"\t!!!!!Remember it must be odd so that matrix can be magic\n\n";
	cout<<"\tNumber of rows=columns:";
	cin>>row_col;
	if(check_odd(row_col)!=1)
	{
		cout<<"\tPlease number of rows==columns and must be odd\n";
		cout<<"\tSo, try again please!\n";
		goto Retry;
	} 
	int Magic[row_col][row_col]={8,1,6,3,5,7,4,9,2};


	//Reading matrice's element


	cout<<"\n\n\t****Now, get ready we are going to enter matrix element row by row****\n\n";
	for (int i=0;i<row_col;i++)
	{
		
 	
		cout<<"Row "<<i+1<<":\n";
		for(int j=0;j<row_col;j++)
		{
			cout<<"\tColumn "<<j+1<<":";
			cin>>Magic[i][j];
			cout<<"\n";
		}

	}

	//Adding first row

	for(int k=0;k<row_col;k++)
	{
		int row=0;
		Sum_row+=Magic[row][k];
	}

	//Adding fisrt column

	for(int k=0;k<row_col;k++)
	{
		int col=0;
		Sum_col+=Magic[k][col];
	}

	//Adding diagonal

		for(int k=0;k<row_col;k++)
	{
		Sum_diagonal+=Magic[k][k];
	}
		
	//Printing entered matrix

	cout<<"This matrix:\n";
	for(int k=0;k<row_col;k++)
	{
		cout<<"\t\t|";
		for(int n=0;;n++)
		{
			if(n==row_col-1)				
			{	cout<<Magic[k][n];
				break;
			}
			else
			{
				cout<<Magic[k][n]<<"\t";
			}
					
		}
		cout<<"|\n\n";
	}

	//Checking whether matrix is Magic square matrix


	if((Sum_col==Sum_row)&&(Sum_col==Sum_diagonal))
	{
		cout<<"\t\tIs square magic matrix\n";
		cout<<"\t\t**********************\n\n";
		cout<<"\t\t******Congrats!!******\n";
	}
	else
	{
		cout<<"\t\tIs not square magic matrix\n";
		cout<<"\t\t***************************\n\n";
		
	}

	system("pause");
	return 0;
}

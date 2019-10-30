#include<iostream>
#include<vector>
using namespace std;

int main()
{
int n;

cout<<"Enter the number of variables\n";
cin>>n;

vector< vector<float> > A(n);


for(int i = 0; i < n; i++)
	A[i].resize(n+1);

cout<<"Enter the system matrix in a raster fashion\n";

for (int i=0;i<n;i++)
{
	for (int j=0;j<n;j++)
	{
		cin>> A[i][j];
	}
}

cout<<"\n";

cout<<"Enter the measurement vector. It must have the same length as the system matrix\n";

for (int i=0;i<n;i++)
	cin>>A[i][n]; //A is now the augmented matrix:A|b


//display augmented matrix
cout<<"A=\n";
for(int i=0;i<n;i++)
{
	for (int j=0;j<n+1;j++)
	{
		cout<<A[i][j]<<" ";
	}
	cout<<"\n";
}


//Begins Gaussian elimination
int pivot_row;
float temp,mul;
for (int i=0;i<n-1;i++)
{
	pivot_row=i;
	for (int j=i+1;j<n;j++)
	{
		if(A[j][i]>A[pivot_row][i])
			pivot_row=j;
	}
	if (pivot_row>i)
	{
		for (int col=i;col<n+1;col++)
		{
			temp=A[i][col];
			A[i][col]=A[pivot_row][col];  //Partial pivoting
			A[pivot_row][col]=temp;
		}
		cout<<"augmented matrix after"<<(i+1)<<"th swapping\n";
		for (int iiii=0;iiii<n;iiii++)
		{
			for(int jjj=0;jjj<n+1;jjj++)
			{
				cout<<A[iiii][jjj]<<" ";
			}		
	
			cout<<"\n";
		}
	}
	
	

	for (int row=i+1;row<n;row++)
	{
		mul=A[row][i]/A[i][i];
		for (int col2=i;col2<n+1;col2++)
			A[row][col2]=A[row][col2]-A[i][col2]*mul; 
	}


	
}
//print the resultant triangular system
cout<<"The reduced system matrix\n";
for (int i=0;i<n;i++)
{
	for(int j=0;j<n+1;j++)
	{
		cout<<A[i][j]<<" ";
	}
	
	cout<<"\n";
}

//Begins back substiution
int sum;
vector<float>X;
X.resize(n);

if (A[n-1][n-1]==0)
{
	cout<<"Unique solution does not exist\n";
}
	
else
{
	
	X[n-1]=A[n-1][n]/A[n-1][n-1];
	for (int row1=n-1; row1>0;row1=row1-1)
	{
		sum=0;
		for(int col3=row1+1;col3<=n;col3=col3+1)
		{
			sum=sum-A[row1-1][col3-1]*X[col3-1];
		}
		 X[row1-1] = (A[row1-1][n] + sum) / A[row1-1][row1-1];
	}
	
	cout<<"The solution is\n";

	for(int ii=0;ii<n;ii++)
	{
		cout<<X[ii]<<"\n";
	}	
}



return 0;
}


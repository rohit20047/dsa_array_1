#include<iostream>
using namespace std;
void bin(int arr[] , int size , int k)

{ cout<<"working"<<endl;
	int mid,high,low , left , right , r , l;
	high=size - 1;
	low = 0;
	mid = (high + low)/2;
	cout<<"working"<<endl;
	while(high >= low)
	{
		if (k == arr[mid])
		{   //cout<<"working"<<endl;
			//for left side
			 left = mid ;
		//	cout<<left<<"in left"<<endl;
			while(arr[left]==k)
			{
			  left--;
			} 
			
			//for right side
		//	cout<<right<<"in right"<<endl;
			 right =mid;
			while(arr[right]==k)
			{
				right++;
			}
			 
			l=left+1;
			r =right-1;
			break;
			
		}
	//	cout<<arr[mid]<<endl;
		if(k > arr[mid])
		{
		//	cout<<left<<endl;
			low = mid+1;
			
		}
		if(k < arr[mid])
		{
			high = mid-1;
		}
		mid = (high + low )/2;
	}
	cout<<"left === "<<l;
	 cout<<"right ====="<<r;
	
}
/*void intersection(int arr[] ,int ar[], int size, int size1)
{
	for(int j = 0 ; j < size ; j++)
     {
     	for(int i = 0 ; i < size1 ; i++)
     	{   
     	//cout<<arr[i]<<ar[j];
     		if (arr[i]==ar[j])
     		{    
     			cout<<arr[i];
     			arr[i]= 999;
     			break;
     			
			 }
			 
			
		 }
	 }
}*/
//void intersection(vector<int> v )

   

int num(int arr[] , int size)
/*{
	for(int j = 0 ; j < size ; j++)
{
         int cout = 0;
	for(int k = 0 ; k < size ; k++)
	{
	      //int cout = 0;
		if (arr[j]==arr[k])
		      cout++;
		else
		   continue;
	
	}
		if(cout==1)
		return arr[j];
}
}*/    // my method(to find single element)
 /*  {
   	int ans = 0 ; 
   	for (int i =0 ; i< size ; i++)
   	{
   		ans = ans^ arr[i];
	   }
	   return ans;
   }//XOR method (to find single element)*/
{  	 int s[10];
int  u[10];
int num;
    for (int i = 0 ; i < size ; i++)
    {
    //	int s[10];
    	int cout =0;
    	for(int k= 0 ; k<size ; k++)
    	{
		      int num =0;
    		if (s[k]==arr[i])
    		   num++;
    		   
        }
        
        if(num != 1)
        {
        	continue;
		}
    		
    	
			
    	for(int j = 0 ; j < size ; j++)
    	{
    	
			
    		if(arr[i]==arr[j])
    		{
    			cout++;
    			s[i]=arr[i];
			}
	     	
		}
		for(int l = 0 ; l<size ; l++)
		{
			u[l]=cout;
		}
        	}
        	
        for(int o = 0 ;o<size;o++)
		cout<<s[o];	
			
			
   	for(int p = 0 ; p < 3 ; p++)
   	{
   		for(int g = 0 ; g < 3 ; g++)
   		{
   			if (u[p]==u[g])
   			   return 1;
   			   else
   			   return 0;
		   }
	   }
   
}
		
	
int main()
{ 
	int size , size1;
	cout<<"enter the sizes";
	cin>>size;
	//cin>>size1;
	int arr[10];
	cout<<endl<<"enter the elements";
	for(int i = 0 ; i<size ; i++)
	cin>>arr[i];
	cout<<"enter the key"<<endl;
	int k;
	cin>>k;
	bin(arr , size , k);
	
//	int ar[10];
//	cout<<endl<<"enter the elements";
//	for(int i = 0 ; i<size1 ; i++)
//	cin>>ar[i];
/*	int e = num(arr , size);
	cout<<"the req num is "<<e;
	int e = num(arr , size);
	if(e==1)a
	cout<<"false";
	else
	cout<<"true";*/
     //intersection(arr ,size);
    
}


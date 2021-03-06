#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int BinarySearch(int array[],int i)
{
	int lowerBound=1;
	int upperBound=i;
	int middlePoint;
	int num;	   //Number to be searched
	int flag=1;
	FILE *fptr;    	   //File pointer
	
	printf("Enter the number to be searched:");
	scanf("%d",&num);
	
	fptr=fopen("binary.html","w");
	fprintf(fptr,"<HTML>\n");
	if(fptr == NULL)
   	{
        	fprintf(fptr,"<p>the error with file open is %d</p>\n",errno);
        	fprintf(fptr,"%s\n",strerror(errno));
        	fprintf(fptr,"</HTML>\n");
        	fclose(fptr);
        	exit(0);
    	}
	while(flag==1)
	{
		if(upperBound<lowerBound)
		{
			fprintf(fptr,"%s","<H1><b><center>Number does not exist</center></b></H1>");
			fprintf(fptr,"</HTML>\n");
			flag=0;
		}
		
		middlePoint=lowerBound+(upperBound-lowerBound)/2;
		
		if(array[middlePoint]<num)
		lowerBound=middlePoint+1;
		
		else if(array[middlePoint]>num)
		upperBound=middlePoint-1;
		
		else if(array[middlePoint]==num)
		{
			fprintf(fptr,"<H1><b><center>%d found at location %d</center></b></H1>",num,middlePoint+1);
			flag=0;
		}
	}
	fprintf(fptr,"</HTML>\n");
	fclose(fptr);
}

main()
{
	FILE *ptr;    	  //File pointer
	int x;		  //Value read from file
	int idx=0;    	  //Index of the array
	int num;	  //Number to be searched
	int val;	 
	int flag=1;
	int numArray[1000];
	
	ptr=fopen("numsort.txt","r");
	if (ptr == NULL)
   	{
     	    printf("Unable to too open the file\n");
            exit(1);
  	}
	while(flag==1)
	{
	    val=fscanf(ptr,"%d",&x);
	    if(val==EOF)
	    {
		flag=0;
	    }
	    else
	    {
	    	numArray[idx]=x;
		printf("%d\n",numArray[idx]);
		idx++;
	    }
	}
	
	BinarySearch(numArray,idx);	
	fclose(ptr);
}

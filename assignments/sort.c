//Kevin Le
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv, char **env)
{
     int array[argc-1],i,j,tmp;
     
     for(i=0;i<argc-1;i++)
     {
         array[i]=atoi(argv[i+1]);
     }
     
     for(i=0;i<argc-1;i++)
     {
           for(j=0;j<argc-1-i;j++)
           {
                 if(array[j]>array[j+1])
                 {
                       tmp=array[j];
                       array[j]=array[j+1];
                       array[j+1]=tmp;
                 }
           }
     }
     
     printf("\n Sorted Array: ");
     for(i=0;i<argc-1;i++)
     {
           printf(" %d",array[i]);
          
     }
           printf("\n");
           printf(" Unsorted Array: ");
    
         for(i=1;i<argc;i++)
     {
           printf(" %s",argv[i]);
          
     }
    
    
    printf("\n");
    
}

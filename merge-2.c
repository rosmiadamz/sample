#include<stdio.h>
void main()
{
int array1[50],array2[50],m,n,i,j,k=0,o,a;
printf("\nEnter the size of the First array");
scanf("%d",&m);
printf("\n Enter the sorted elements of First array\n");
for(i=0;i<m;i++)
{
scanf("%d",&array1[i]);
}
printf("\n Enter the size of the Second Array:");
scanf("%d",&n);
printf("\n Enter the sorted elements of Second array\n");
for(i=0;i<n;i++)
{
scanf("%d",&array2[i]);
}
o=m+n;
int c[o];
for (i = 0;i<m; i++) 
{
        c[i] = array1[i];
    }
for (i = 0, j = m;j < o && i < n; i++, j++) 
{
        c[j] =array2[i];
    }
for (i = 0; i < o; i++)
 {
        printf("%d ", c[i]);
    }
        for (i = 0; i < o;i++) 
  {
 for (j = i + 1; j < o;j++)
 {
     if (c[i] > c[j])     
 {

   a = c[i];
   c[i] = c[j];
   c[j] = a;
   }
 }
  }
printf("\nThe numbers arranged in ascending order are given below \n");

 for (i = 0; i < o;i++)
 printf("%d\n",c[i]);
    return 0;
}


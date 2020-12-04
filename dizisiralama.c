#include <stdio.h>
#include <stdlib.h>

int *sirala(int* first , int second )
{
  int united[16];
  int i=0 , j=0, k=0;
  while (k<16)
  {
      if (i==8)
      {
     united[k]=second[j];
          j++;
          k++;
    }
  else if (j==8)
  {
      united[k]=second[i];

      i++;
      k++;
  }
    else if(first[i]< second[j])
    {
        united [k] =first [i] ;
        i++;
        k++;
        }
        else
        {
            united[k]=second[j];
            j++;
            k++;
        }
  }
}
    int* u=united
    return u;

     int main ()
     {
         int f[8],s[8], res[16], *r;
         for(int i=0;i<8;i++)
         {
             printf(Enter %d th value (for first array) :\n", i);
             scanf ("%d", & f[i] );
         }
         for ( int j=0;j<8;j++)
         {
            printf ("Enter %d value (for second array) :\" , j )
            scanf ("%d" ,&s[j]);
         }
         r=sirala(f,s);
         for (int y=0;y<16;y++)
        res[y]=*(r+y);
        printf("United array :");
        for (int k=0; k<16;k++)
        {
            printf ("%d", res[k]);
        }
}
















     }













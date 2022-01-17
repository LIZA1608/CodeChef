//Problem Code: CIRCLEGAME

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
  public static void main (String[] args) throws java.lang.Exception
  {
      Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    while(t-->0)
    {
        int m=sc.nextInt();
        int x=sc.nextInt();
        m--;
        int a[]=new int[x];
        a[0]=1;
        int ps,i;
        for(i=1;i<x;i++)
        {
            ps=(m%(i+1))+1;
            if(a[i-1]<ps)
            a[i]=a[i-1];
            else{
                a[i]=a[i-1]+1;
            }
        }
        for(i=0;i<x;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }
  }
}

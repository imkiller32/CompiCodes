import java.util.*;
import java.math.*;
class GEOPRB
{
    public static void main(String args[]) 
    {
        long  t,i;
		Scanner sc=new Scanner(System.in);
		t=sc.nextLong();
		BigInteger a[]=new BigInteger[4];
		for(i=0;i<t;i++)
		{
			a[0]=sc.nextBigInteger();
			a[1]=sc.nextBigInteger();
			a[2]=sc.nextBigInteger();

			a[3]=(a[1].subtract(a[0])).add(a[1].subtract(a[2]));
	
			System.out.println(a[3]);		
		}
    }
}
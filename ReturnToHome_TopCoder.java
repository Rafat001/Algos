import java.awt.Dialog.ModalExclusionType;
import java.util.Scanner;

public class ReturnToHome {
	public static double goHome(int x, int y, int d, int t){
		double ds,dc,a,b,c,temp,dts,mn;
		int xx;
		ds=(x*x)+(y*y);
	    ds=Math.sqrt(ds);
	    if((ds % d)==0)
	    {
	        a=ds;
	        b=ds/d;
	        b*=t;
	        mn=Math.min(a, b);
	    }
	    else
	    {
	        c=temp=0;
	        a=ds;
	        if(x==y)
	            a=x;
	        dts=Math.floor(ds/d);
	        b=dts;
	        b*=t;
	        dc=ds-(dts*d);
	        b+=dc;
	        while(c<ds)
	        {
	            c+=d;
	            temp+=t;
	        }
	        temp+=(c-ds);
	        c=(int)(ds-d)/d;
	        c=c*t+2*t;
	        mn=Math.min(Math.min(temp,Math.min(a,b)),c);
	    }
	    return mn;
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int x,y,d,t;
		x=sc.nextInt();
		y=sc.nextInt();
		d=sc.nextInt();
		t=sc.nextInt();
		double mn=goHome(x,y,d,t);
		System.out.println(mn);
	}
}

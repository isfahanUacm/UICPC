import java.util.*;

public class Connect_jm
{	
	private static int a[][],queue[],head,tail;
	
	private static void add(int x, int y, int step)
	{
		if (a[y][x]==0 || a[y][x]==-1) {
			a[y][x]=step;
			queue[tail++]=y*1000+x;
		}
	}
	
	private static int search(int xsize, int ysize, int x1, int y1, int x2, int y2)
	{
		head=tail=0;
		add(x1,y1,1);		
		while (head<tail) {
			x1=queue[head]%1000;
			y1=queue[head++]/1000;
			int step=a[y1][x1];
			if (x1==x2 && y1==y2) return step-1;
			if (x1>0) add(x1-1,y1,step+1);
			if (y1>0) add(x1,y1-1,step+1);
			if (x1+1<xsize) add(x1+1,y1,step+1);
			if (y1+1<ysize) add(x1,y1+1,step+1);
		}
		return -1;		
	}
	
	private static int connect(int x1, int y1, int x2, int y2, int dir)
	{		
		int len=Math.abs(x1-x2)+Math.abs(y1-y2);		
		
		a[y1][x1]=-2;				
		while (x1!=x2 || y1!=y2) {
			if ((dir&1)==0 && x1<x2 && a[y1][x1+1]==0) { x1++; if (dir>1) dir-=3; }
			else if ((dir&1)==0 && x1>x2 && a[y1][x1-1]==0) { x1--; if (dir>1) dir-=3; }
			else if ((dir&1)==1 && y1<y2 && a[y1+1][x1]==0) { y1++; if (dir>1) dir-=3; }
			else if ((dir&1)==1 && y1>y2 && a[y1-1][x1]==0) { y1--; if (dir>1) dir-=3; }
			else {
				if (dir>1) return -1;
				dir+=3;
			}
			a[y1][x1]=-2;
		}
			
		return len;
	}	

	public static void show(int[][] a, int xsize, int ysize)
	{
		for(int i=0;i<ysize;i++) {
			for(int j=0;j<xsize;j++) System.out.print(a[i][j]+" ");
			System.out.println();
		}
		System.out.println();
	}
	
	public static int shortestWires(int xsize, int ysize, int[] X, int[] Y)
	{
		int best=-1,u,v;
		queue=new int[xsize*ysize];
		
		for(int i=0;i<4;i+=2) {
			for(int j=0;j<2;j++) {
				a=new int[ysize][xsize];
				int x1=X[i^j],y1=Y[i^j],x2=X[(i+1)^j],y2=Y[(i+1)^j];
				int x3=X[(i^2)^j],y3=Y[(i^2)^j],x4=X[((i^2)+1)^j],y4=Y[((i^2)+1)^j];
				
				a[y3][x3]=a[y4][x4]=-1;
				u=connect(x1,y1,x2,y2,0);
				v=search(xsize,ysize,x3,y3,x4,y4);
				if (u>=0 && v>=0 && (u+v<best || best<0)) best=u+v;
				
				//show(N);
			
				a=new int[ysize][xsize];
				a[y3][x3]=a[y4][x4]=-1;
				u=connect(x1,y1,x2,y2,1);
				v=search(xsize,ysize,x3,y3,x4,y4);
				if (u>=0 && v>=0 && (u+v<best || best<0)) best=u+v;
				
				//show(N);
			}
		}
	
		// Special case when all are on same row/col, overlapping each other
		if (best==-1) {
			if (X[0]==X[1] && X[0]==X[2] && X[0]==X[3] && X[0]>0 && X[0]+1<xsize)
				best=Math.abs(Y[0]-Y[1])+Math.abs(Y[2]-Y[3])+4;
			else if (Y[0]==Y[1] && Y[0]==Y[2] && Y[0]==Y[3] && Y[0]>0 && Y[0]+1<ysize)
				best=Math.abs(X[0]-X[1])+Math.abs(X[2]-X[3])+4;
		}			
		
		return best;
	}
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(System.in);
		int xsize = in.nextInt(), ysize = in.nextInt();
		if (xsize < 1 || ysize < 1 || xsize > 100 || ysize > 100) throw new Exception();
		int X[] = new int[4], Y[] = new int[4];
		for(int i=0;i<4;i++) {
			X[i] = in.nextInt();
			Y[i] = in.nextInt();
			if (X[i] < 0 || X[i] > xsize || Y[i] < 0 || Y[i] > ysize) throw new Exception();
			for(int j=0;j<i;j++)
				if (X[i]==X[j] && Y[i]==Y[j]) throw new Exception();
		}
		int ans = shortestWires(xsize+1, ysize+1, X, Y);
		if (ans >= 0)
			System.out.println(ans);		
		else
			System.out.println("IMPOSSIBLE");
	}
}

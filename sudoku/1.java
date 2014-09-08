import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Sudoku {

	public static int[][] model;
	static int cnt =0;
	public static  void createModel() throws IOException
	{
			model = new int[9][9]; 
		
		//{{0,2,0,0,0,0,0,0,0}, 
//			 {0,0,0,6,0,0,0,0,3}, 
//			 {0,7,4,0,8,0,0,0,0},
//			 {0,0,0,0,0,3,0,0,2},
//			 {0,8,0,0,4,0,0,1,0},
//			 {6,0,0,5,0,0,0,0,0},
//			 {0,0,0,0,1,0,7,8,0},
//			 {5,0,0,0,0,9,0,0,0},
//			 {0,0,0,0,0,0,0,4,0}};
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<9;i++)
		{
			String[] input = br.readLine().split("\\s+");
			for(int j=0;j<9;j++)
			{
				int k = Integer.parseInt(input[j]);
				model[i][j]=k;
			}
		}
		}
	
	public static  boolean solve(int r , int c) //throws Exception
	{
		//if(r>8) throw new Exception("solved");
		cnt++;
		if(c==9)
		{
			c=0;
			if(++r == 9)
				return true;
		}
		
		if(model[r][c]!=0)
			return solve(r,c+1);
		else
		{
			for(int num = 1;num<=9;num++)
			{
			//	System.out.print(num+" ");
				if(checkRow(r, num) && checkCol(c, num) && checkBox(r,c,num))
				{
					model[r][c]=num;
					if(solve(r,c+1))
						return true;
				}
			}
			model[r][c]=0;
			return false;
		}
		
	}
	private  static boolean checkBox(int r, int c, int num) {
		r = (r/3)*3;
		c=  (c/3)*3;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(model[r+i][j+c]==num)
					return false;
		return true;
	}

	private   static boolean checkCol(int c, int num) {
		for(int r=0;r<9;r++)
			if(model[r][c]==num)
				return false;
		return true;
	}

	private  static boolean checkRow(int r, int num) {
		for(int c=0;c<9;c++)
			if(model[r][c]==num)
				return false;
		return true;
	}


	public static void main(String[] args) throws IOException {
		
		
		createModel();
		long start_time = System.currentTimeMillis();
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				System.out.print(model[i][j]+" ");
			}
			System.out.println();
		}
		
		solve(0, 0);

		
		long end_time = System.currentTimeMillis();
		
		System.out.println(end_time-start_time);
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				System.out.print(model[i][j]+" ");
			}
			System.out.println();
		}
	}

}

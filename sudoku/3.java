package com.sudoku2;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


/*
0 2 0 0 0 0 0 0 0 	
0 0 0 6 0 0 0 0 3
0 7 4 0 8 0 0 0 0 
0 0 0 0 0 3 0 0 2
0 8 0 0 4 0 0 1 0 
6 0 0 5 0 0 0 0 0
0 0 0 0 1 0 7 8 0
5 0 0 0 0 9 0 0 0
0 0 0 0 0 0 0 4 0 


0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0 
8 2 0 1 0 0 0 4 0 
0 0 4 6 0 2 9 0 0 
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0 


1 0 0 4 8 9 0 0 6
7 3 0 0 0 0 0 4 0
0 0 0 0 0 1 2 9 5
0 0 7 1 2 0 6 0 0 
5 0 0 7 0 3 0 0 8
0 0 6 0 9 5 7 0 0 
9 1 4 6 0 0 0 0 0
0 2 0 0 0 0 0 3 7
8 0 0 5 1 2 0 0 4

8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0 
0 5 0 0 0 7 0 0 0 
0 0 0 0 4 5 7 0 0 
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0 
0 9 0 0 0 0 4 0 0 

	*/

class Game
{
	List<Integer> pos = new ArrayList<Integer>();
	int num=0;
	boolean fixed = false;
	
}
public class SudokuMethod2 {

	public static Game[][] model;
	
	static int cnt1 =0;
	
	public static  void createModel() throws NumberFormatException, IOException
	{
		model = new Game[9][9];
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				model[i][j] = new Game();

		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<9;i++)
		{
			String[] input = br.readLine().split("\\s+");
			for(int j=0;j<9;j++)
			{
				int k = Integer.parseInt(input[j]);
				if(k!=0)
				{
					cnt1++;
					model[i][j].fixed = true;
					model[i][j].pos.add(k);
					model[i][j].num = k;
				}
				else 
				{
					model[i][j].fixed = false;
					model[i][j].num=0;
					for(int m=1;m<=9;m++)
						model[i][j].pos.add(m);
				}
			}
		}
		
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(model[i][j].fixed == true)
				{
					int num = model[i][j].pos.get(0);
					for(int k=0;k<9;k++)
					{
						if(j!=k && model[i][k].pos.contains(num))
						{	
								model[i][k].pos.remove(model[i][k].pos.indexOf(num));
						}
					}
					for(int k=0;k<9;k++)
					{
						if(i!=k && model[k][j].pos.contains(num))
						{
								model[k][j].pos.remove(model[k][j].pos.indexOf(num));
						}
					}
					
					int r = (i/3)*3;
					int c = (j/3)*3;
					for(int k=0;k<3;k++)
					{
						for(int m=0;m<3;m++)
						{
							if(k+r!= i && m+c!=j  && model[k+r][m+c].pos.contains(num))
							{
									model[k+r][m+c].pos.remove(model[k+r][m+c].pos.indexOf(num));
							}
						}
					}
				}
			}
		}		
	}
	
	public static  boolean solve(int r , int c) 
	{
		if(c==9)
		{
			c=0;
			++r;
			if(r>9) return false;
			if(r==9 && cnt1==81) return true;
			if(cnt1==81) return true;
			if(r==9 && c==0 && cnt1!=81) return false;
		}
		
		if(cnt1!=81)
		{
			if(model[r][c].pos.size()==1 && model[r][c].fixed==false)
			{
				int num = model[r][c].pos.get(0);
				model[r][c].fixed = true;
				model[r][c].num = num;
				cnt1++;
				removeFromCol(r,c,num);
				removeFromRow(r,c,num);
				removeFromBox(r,c,num);
			}
			return solve(r,c+1);
		}
		return true;				
	}

	
	private static void removeFromBox(int r, int c, int num) {
		int i =( r/3)*3;
		int j = (c/3)*3;
		for(int k=0;k<3;k++)
		{
			for(int m=0;m<3;m++)
			{
				if(k+i!= r && m+j!=c && !model[k+i][m+j].fixed && model[k+i][m+j].pos.contains(num))
					{
						model[k+i][m+j].pos.remove(model[k+i][m+j].pos.indexOf(num));
						if(model[k+i][m+j].pos.size()==1 &&  model[k+i][m+j].fixed==false)
						{
							model[k+i][m+j].fixed=true;
							model[k+i][m+j].num =model[k+i][m+j].pos.get(0);
							cnt1++;
							removeFromCol(k+i,m+j,model[k+i][m+j].pos.get(0));
							removeFromRow(k+i,m+j,model[k+i][m+j].pos.get(0));
							removeFromBox(k+i,m+j,model[k+i][m+j].pos.get(0));
						}
			
					}
			}
		}
	}

	private static void removeFromRow(int r, int c, int num) {
		for(int k=0;k<9;k++)
		{
			if(c!=k && !model[r][k].fixed && model[r][k].pos.contains(num))
				{
					model[r][k].pos.remove(model[r][k].pos.indexOf(num));
					if(model[r][k].pos.size()==1 &&  model[r][k].fixed==false)
					{
						model[r][k].fixed=true;
						model[r][k].num = model[r][k].pos.get(0);
						cnt1++;
						removeFromCol(r,k,model[r][k].pos.get(0));
						removeFromRow(r,k,model[r][k].pos.get(0));
						removeFromBox(r,k,model[r][k].pos.get(0));
					}
				}
			}
	}

	private static void removeFromCol(int r, int c, int num) {
		for(int k=0;k<9;k++)
		{
			if(r!=k &&  !model[k][c].fixed && model[k][c].pos.contains(num))
			{
					model[k][c].pos.remove(model[k][c].pos.indexOf(num));
					if(model[k][c].pos.size()==1  &&  model[k][c].fixed==false)
					{
						model[k][c].fixed=true;
						model[k][c].num = model[k][c].pos.get(0);
						cnt1++;
						removeFromCol(k,c,model[k][c].pos.get(0));
						removeFromRow(k,c,model[k][c].pos.get(0));
						removeFromBox(k,c,model[k][c].pos.get(0));
					}
				}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
	
		createModel();
		
		Long start_time = System.currentTimeMillis();
		/*for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				System.out.println(i+" "+j+ " "+model[i][j].pos.toString()+" "+model[i][j].fixed);
			}
			System.out.println();
		}
		System.out.println();*/
		
		if(solve(0, 0)==false)
		{
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					System.out.print(model[i][j].num+" "+model[i][j].fixed+ "  ");
				}
				System.out.println();
			}
			Sudoku.solve(0, 0 , model);
		}

		long end_time = System.currentTimeMillis();
		System.out.println(end_time-start_time);
		
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				System.out.print(model[i][j].num+"  ");
			}
			System.out.println();
		}
	}
}

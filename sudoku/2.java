package com.sudoku2;

public class Sudoku {

	public static  boolean solve(int r , int c, Game[][] model) //throws Exception
	{
		if(c==9)
		{
			c=0;
			if(++r == 9)
				return true;
		}
		
		if(model[r][c].fixed==true)
			return solve(r,c+1, model);
		else
		{
			for(int i = 0;i<model[r][c].pos.size();i++)
			{
				int num =  model[r][c].pos.get(i);
				if(checkRow(r, num, model) && checkCol(c, num, model) && checkBox(r,c,num, model))
				{
					model[r][c].fixed=true;
					model[r][c].num=num;
					if(solve(r,c+1,model))
					{
						return true;
					}
				}
			}
			model[r][c].num=0;
			model[r][c].fixed=false;
			return false;
		}
		
	}
	private  static boolean checkBox(int r, int c, int num, Game[][] model) {
		r = (r/3)*3;
		c=  (c/3)*3;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(model[r+i][j+c].num==num)
					return false;
		return true;
	}

	private   static boolean checkCol(int c, int num, Game[][] model) {
		for(int r=0;r<9;r++)
			if(model[r][c].num==num)
				return false;
		return true;
	}

	private  static boolean checkRow(int r, int num, Game[][] model) {
		for(int c=0;c<9;c++)
			if(model[r][c].num==num)
				return false;
		return true;
	}

}

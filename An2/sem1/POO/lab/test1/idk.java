import java.io.*;

class Test
{
	private double x;
	private int[] v = new int[100];
	public Test(double x)
	{
		this.x = x;
	}

	public boolean equals(Object o)
	{
		Test t = (Test) o;
		if(o instanceof Test)
		{
			if(t.x == this.x)
				return true;
			else 
				return false;
		}
		return false;
	}

	public String toString()
	{
		return "x=" + x;
	}
}

class Main
{
	public static void main(String[] argv)
	{
		try 
		{
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);
			/*
			FileInputStream fis = new FileInputStream("fisier.txt");
			BufferedReader br2 = new BufferedReader(new InputStreamReader(fis));*/

			int n = Integer.parseInt(br.readLine());
			Test t1 = new Test(2.5);
			Test t2 = new Test(2.5);
			System.out.println(t1.equals(t2));
			System.out.println(t1);

			Test[] t = new Test[100];
			for(int i = 0; i < n; i++)
			{
				t[i] = new Test();
			}
		}
		catch(IOException e)
		{
			System.out.println("Nu s-a putut citi!");
		}
	}
}
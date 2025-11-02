class Test
{
	private int x;

	public Test(int x)
	{
		this.x = x;
	}

	public boolean equals(Object o)
	{
		Test t = (Test) o;
		if(o instanceof Test)
		{
			if(this.x == t.x)
				return true;
			return false;
		}
		return false;
	}

}

class Main
{
	public static void main(String[] argv)
	{
		Test t1 = new Test(2);
		Test t2 = new Test(3);
		Test t3 = new Test(2);
		System.out.println(t1.equals(t2));
		System.out.println(t1.equals(t3));
	}
}
class ex3 {
	public static void main(String argv[])
	{
		int S = 0;
		for(int i = 1; i <= 100; i++)
			if(i%2 == 1)
				System.out.println(i);
			else 
				S = S + i;
		System.out.println(S);
	}
}
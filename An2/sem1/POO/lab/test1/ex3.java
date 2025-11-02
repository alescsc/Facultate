import java.io.*;

class Main
{
	public static void main(String[] argv)
	{
		try 
		{
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);
			String linie = br.readLine();
			String fisier = br.readLine();

			FileInputStream isf = new FileInputStream(fisier);
			BufferedReader br2 = new BufferedReader(new InputStreamReader(isf));

			String linie2;
			int k = 0;
			while((linie2 = br2.readLine()) != null)
			{
				if(linie2.equals(linie))
					k++;
			}
			System.out.println(k);
			br2.close();
			br.close();
		}
		catch(IOException e)
		{
			System.out.println("Eroare la citire!");
		}
	}
}
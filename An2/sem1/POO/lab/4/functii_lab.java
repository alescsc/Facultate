class Main
{
	public static void main(String[] argv)
	{
		String sir = new String("Dori e foarte cool!!!");
		String sir2 = sir.concat(" Toata lumea o stie!"); // sau = sir + "...";

		System.out.println(sir);
		System.out.println(sir2);

		System.out.println(sir.charAt(1)); // returneaza caracterul aflat la pozitia indicata
		
		System.out.println(sir.endsWith("!!!")); // verifica daca sirul se termina cu sufixul precizat
		
		System.out.println(sir.equals(sir2)); // verifica daca 2 siruri sunt egale
		
		System.out.println(sir.indexOf("D")); // afiseaza pozitia primei aparitie a caracterului/subsirului
		
		System.out.println(sir.lastIndexOf("o")); // afiseaza pozitia ultimii aparitiei a caracterului/subsirului
		
		System.out.println(sir.length()); // afiseaza lungimea sirului de caractere

		System.out.println(sir.startsWith("Dori")); // verifica daca sirul incepe cu subsirul apelat 

		System.out.println(sir.substring(5)); // afiseaza subsirul incepand de la pozitia 4

		System.out.println(sir.toUpperCase()); // afiseaza tot sirul cu CAPS


		String s = new String("123");
		int nr = Integer.parseInt(s);
		System.out.println(nr + 2); // afiseaza valoarea ca int din string
	}
}
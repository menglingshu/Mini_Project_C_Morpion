public class Ordre{
	public static void reverse(String chaineAInverser){
		int longeur = chaineAInverser.length();
		String Inverser = "";
		for(int i = longeur-1; i>=0; i--)
			Inverser = Inverser + chaineAInverser.charAt(i);
		System.out.println("" + Inverser + "");
	}
	public static void main(String[] args){
		for(int i = 0; i<args.length; i++)
			reverse (args[i]);
	}
}


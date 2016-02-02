public class Fizzbuzz{
	public static String transf(int n){
		if (n%5==0 && n%7==0)
			return "fizzbuzz";
		else if (n%7==0 && n%5!=0)
			return "buzz";
		else if(n%5==0 && n%7!=0)
			return "fizz";
		else
			return (""+n);
	}
	public static void main(String[] args){
		int n;
		int max = 100;
		for(n=1;n<=max;n++)
			{System.out.println("le resultat de" + n + " " + "est" + " " + transf(n) );}
	}
}	
	

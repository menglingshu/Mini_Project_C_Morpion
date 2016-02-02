public class Hanoi{
	public static void deplace(int n , char dep, char inter, char arr){
		if (n > 0){
			deplace(n - 1, dep, arr, inter);
		 	System.out.println("rondelle "+ n + " depart " + dep + " arrive " + arr);
		 	deplace(n - 1, inter, dep, arr);
		}	
	}
	public static void main(String[] args) {
		int nbrondelle = 3;
		deplace(nbrondelle, 'A', 'B', 'C');
	}
}

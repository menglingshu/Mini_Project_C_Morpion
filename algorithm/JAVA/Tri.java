public class Tri{
	public static int posMin(int []t, int d, int f){
		int min = d;
		for(int i=d+1; i<=f; i++){
		if(t[min]> t[i])
			min=i;
		}
		return min;
	}
	public static void trier(int []t){
		int min, temp;
		for(int i=0;i<t.length; i++){
		min = posMin(t, i, t.length-1);			
			temp = t[i];
			t[i] = t[min];
			t[min] = temp;
		}
	}
	public static void affiche(int []t){
		for(int i=0;i<t.length;i++){
			System.out.print(t[i] + " ");
		}
		System.out.println();
	}	
	
	public static void main(String[] args){
		
		int[]t = new int[10];
		for(int i=0; i<t.length; i++){
			t[i] = (int)(Math.random()*50 +1);
		}
		affiche(t);
		trier(t);
		affiche(t);
	}
}

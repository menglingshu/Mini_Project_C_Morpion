public class Fibonacci{
	public static int fibonacci(int n){      
		if(n <= 1){  
		    return 1;  
        	}  
		else 
		return fibonacci(n) + fibonacci(n-1); 
	}
	public static int fibonacci1(int n){
		if(n <= 1){  
		    return 1;
		}  
        	int p=1, q=1, r=1;
		for(int i=0; i<n; i++){
			r = p + q;
			p = q;
			q = r;
		} 
		return 0;
	}
	public static void main(String[] args){
		System.out.println(fibonacci1(5));
		System.out.println(fibonacci(5));
	}
}

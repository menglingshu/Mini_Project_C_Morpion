public class Domino{
	private int left;
	private int right;
	
	public Domino(int i, int j){
		left = i;
		right = j;
	}
	public Domino(){
		this(0, 0);
	}
	public int getLeft(){
		return left;
	}
	public int getRight(){
		return right;
	}
	public boolean isDomino(){
		return ((this.right>=0)&&(this.left<=6)&&(left<=0)&&(right<=6)); 
	}
	public boolean isDouble(){
		return left==right;
	}
	public int totalPoint(){
		return left+right;
	}
	public void Rotate(){
		int var;
		var = right;
		right = left;
		left = var;
	}
	public String toString(){
		return "[ " + left +" , " + right + " ] ";
	}
	public boolean equals(Object o){
		if(o instanceof Domino){
			Domino d = (Domino)o;
			return ((left==d.left && right==d.right)||(left==d.right && right==d.left));	
		}
		return false;
	}
	public int compatible(Domino d){
		if(left == d.left)
			return -2;
		if(right == d.left)
			return -1;
		if(right == d.right)
			return 2;
		if(left == d.right)
			return 1;
		return 0;	
	}
	public static void main(String[] args){
		Domino d0 = new Domino();
		Domino d1 = new Domino(5,1);
		Domino d2 = new Domino(1,5);
		Domino d3 = new Domino(4,3);
		Domino d4 = new Domino(5,5);

		System.out.println(d0 + " " + d0.isDomino());
		System.out.println(d1 + " " + d1.isDomino());
		System.out.println(d4 + " " + d4.isDomino());
		System.out.println("equals: " + d1.equals(d2));
		System.out.println("equals: " + d1.equals(d3));
		System.out.println("compatible: " + d1.compatible(d4));
		System.out.println("compatible: " + d2.compatible(d4));
		System.out.println("compatible: " + d1.compatible(d3));		
	}
}

public class PointR2{
	
	public double x;
	public double y;

	public PointR2(double a, double b){
		x = a;
		y = b;
	}
	public PointR2(){
		this(0,0);
	}
	public double distance(PointR2 p){
		return Math.sqrt((p.x-this.x)*(p.x-this.x)+(p.y-this.y)*(p.y-this.y));
	}
	public boolean equals(Object o){
		if(o instanceof PointR2){
			PointR2 p = (PointR2)o;
			return ((x == p.x) && (y == p.y));
		}
		return false;
	}
	public String toString(){
		return "("+ x + "," + y +")";
	}
	public static void main(String[] args){

		PointR2 coord1 = new PointR2(5.0, 6.0);
		PointR2 coord2 = new PointR2(4.0, 2.0);

		System.out.println("egalite :" + coord1.equals(coord2));
		System.out.println("distance :" + coord1.distance(coord2));
	}
}

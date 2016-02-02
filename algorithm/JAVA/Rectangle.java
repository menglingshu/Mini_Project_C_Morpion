public class Rectangle{

	public PointR2 ext1;
	public PointR2 ext2;
	
	public Rectangle(PointR2 p, PointR2 q){
		ext1 = p;
		ext2 = q;
	}
	public Rectangle(){
		this(new PointR2(),new PointR2());
	}
	public Rectangle(PointR2 cig, double lo, double h){
		ext1 = cig;
		ext2 = new PointR2(ext1.x + lo, ext1.y + h);
	}
	public double longueur(){
		double longueur = ext1.x + ext2.x;
		if(longueur<0){
			return -1;}
		return longueur;
	}
	public double hauteur(){
		double hauteur = ext1.y + ext2.y;
		if(hauteur<0){
			return -1;}
		return hauteur;
	}
	public double perimetre(){		
		return (2*(this.longueur()+this.hauteur()));	
	}
	public double surface(){
		return (this.longueur()*this.hauteur());
	}
	public Rectangle symetrique(){
		PointR2 pointrec1 = new PointR2(ext1.y, ext1.x);
		PointR2 pointrec2 = new PointR2(ext2.y, ext2.x);
		return new Rectangle(pointrec1,pointrec2);
	}
	public void normalise(){
		PointR2 cig = new PointR2(Math.min(ext1.x,ext2.x), Math.min(ext1.y, ext2.y)); 
	
	//return le meme rectangle
	//main avec ext1 qui est le cig
	}
	public boolean contient(PointR2 p){
		return ((p.x<=this.ext1.x)&&(p.y<=this.ext1.y)&&(p.x<=this.ext2.x)&&(p.y<=this.ext2.y));
	}
	public static void main(String[] args){
		PointR2 a = new PointR2(5.0, 3.0);
		PointR2 b = new PointR2(7.0, 3.0);
		PointR2 p = new PointR2(3.0, 4.0);
		Rectangle pointrec1 = new Rectangle(a,b);
		Rectangle pointrec2 = new Rectangle(a, 5.0, 6.0);
		System.out.println("la longueur du rectangle est : " + pointrec2.longueur() + "\r\n");
		System.out.println("la hauteur du rectangle est: " + pointrec1.hauteur() + "\r\n");
		System.out.println("le perimetre du rectangle est: " + pointrec1.perimetre() + "\r\n");
		System.out.println("la surface du rectangle est: " + pointrec1.surface()+"\r\n");
	} 	
}

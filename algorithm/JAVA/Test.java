public class Test{
	private static double tauxAlerte=0.22;
	private String nom;
	private int date;
	private double taux;
	
	public Test(String n, int d, double t){
		nom = n;
		date = d;
		taux = t;
	}
	public Test(){
		this(" ", 0, -1);
	}
	public String getNom(){
		return nom;
	}
	public double getTaux(){
		return taux;
	}
	public int getDate(){
		return date;	
	}
	public String toString(){
		return "["+nom+","+date+","+taux+"]";
	}
	public boolean isTest(){
		return this.taux>=0 &&this.taux<=1;
	}
	public boolean alerte(){
		return this.isTest() &&this.taux<=tauxAlerte;
	}
	public double compareTaux(Test t){
		return taux-t.taux;
	}
	public boolean equals(Object o){
		if(o instanceof Test){
			Test t = (Test)o;
			return (date==t.date && nom.equals(t.nom));
		}
		return false;
	}
	public static void main(String[] args){
		Test t1 = new Test("toto", 20150101, 0.57);
		Test t2 = new Test("albertine", 20150102, 0.21);
		Test t3 = t2;
		Test t4 = new Test("albertine", 20150102, 0.21);
		System.out.println(t1+"\r\n");
		System.out.println(t1.getDate()+"\r\n");
		System.out.println(t1.compareTaux(t2)+"\r\n");
		System.out.println(t2.alerte()+"\r\n");
		System.out.println(t1.alerte()+"\r\n");
		System.out.println((t1==t2) +"\r\n");
		System.out.println((t2==t3) +"\r\n");
		System.out.println(t2.equals(t4)+"\r\n");
	}
}

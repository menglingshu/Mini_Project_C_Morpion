public class PileT{
	private static int nbTotal = 10;
	private Object[] tab;
	private int nbElem;

	public PileT(){
		tab = new Object[nbTotal];
		nbElem = 0;
	}
	public void push(Object o){
		if(nbElem < nbTotal){ 
			tab[nbElem]=o;
			nbElem++;
		}
	}
	public boolean isEmpty(){
		return nbElem==0;	
	}
	public Object pop(){
		if(!isEmpty()){
			nbElem--;
			return tab[nbElem];
		}
		return null;
	}
	public Object top(){
		if(!isEmpty()){
			return tab[nbElem];
		}
		return null;
	}		
	public String toString(){
		StringBuffer sb = new StringBuffer();
		for(int i=0; i<nbElem; i++);
		sb.append(tab[1] + "\r\n"); 
		return sb.toString(); 
	}
	public static void main(String[] args){
		PileT t1 = new PileT();
		PileT t2 = new PileT();
		System.out.println(t1+"\r\n");		
		System.out.println(t2+"\r\n");
		t1.push("toto");
		t2.push(123456);
		System.out.println(t1.pop()+"\r\n");
		System.out.println(t2.pop()+"\r\n");
		
	}
}

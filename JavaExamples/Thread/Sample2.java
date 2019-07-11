class Printer{
	synchronized void printDoc(int numCopies, String docName){
		for(int i=1; i <=numCopies; i++){
			System.out.println(">> printing " +docName+ " " +i);
		}
	}
}
class RkpThread extends Thread{
	Printer p;
	RkpThread(Printer p){
		this.p=p;
	}
	public void run(){
		p.printDoc(10,"rkp");
	}
}
class DkpThread extends Thread{
	Printer p;
	DkpThread(Printer p){
		this.p=p;
	}
	public void run(){
		synchronized(p){
			p.printDoc(10,"dkp");
		}
	}
}
class TestPrinter{
	public static void main(String[] args){
		System.out.println("==Application started====");
		Printer p=new Printer();
		RkpThread t1=new RkpThread(p);
		t1.start();
		/*
		try{
		      t1.join();
		}catch(InterruptedException e){
			e.printStackTrace();
		}
		*/
		DkpThread t2=new DkpThread(p);
		t2.start();
		System.out.println("====Aplication end=====");
	}
}


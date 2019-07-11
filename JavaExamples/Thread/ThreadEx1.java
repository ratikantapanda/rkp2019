//Multiple inheritance is not possible in java, so Runnable interface is better.
class MyTask extends Thread{
	@Override 
	public void run(){
		for(int i=0; i < 10; i++){
			System.out.println("i= " + i);
		}
	}
}
class Test{
}
class MyTask2 extends Test implements Runnable{
	@Override 
	public void run(){
		for(int j=0; j < 10; j++){
			System.out.println("j= " + j);
		}
	}
}
class Sample1{
	public static void main(String[] args){
		MyTask t1=new MyTask();
		t1.start();
		for(int k=100; k < 110; k++){
			System.out.println("k= " + k);
		}
		//MyTask2 r=new MyTask2();
		Runnable r=new MyTask2();
		Thread t2=new Thread(r);
		t2.start();
		for(int i=0; i < 5; i++)
		{
			new Thread(new MyTask2()).start();
		}
	}
}

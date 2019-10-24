
interface IGreet{
	public void greet(String name);
}

class Hello implements IGreet{
	@Override 
	public void greet(String name){
		System.out.println("Hello " + name);
	}
}

class TestGreet{
	void invite(IGreet greeter,String name){
		greeter.greet(name);
	}
	public static void main(String[] args){
		TestGreet test=new TestGreet();
		Hello hello=new Hello();
		test.invite(hello,"Ratikanta");
		//Anonymous class
		IGreet hi=new IGreet(){
			public void greet(String name){
				System.out.println("Hi " + name);
			}
		};
		test.invite(hi,"Litu");
		test.invite( new IGreet(){
			public void greet(String name){
				System.out.println("hi.." + name);
			}
		},"litu");
		//Lambdas
		test.invite((n)->System.out.println("Welcome Mr. " + n),"Ratikanta Panda");
	}
}





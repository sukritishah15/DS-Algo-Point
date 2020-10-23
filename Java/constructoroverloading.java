class maths{
	int x;
	int y;
	int add(){
		return (x+y);			
	}
	int sub(){
		return(x-y);
	}
	maths(int a,int b){                 /*Constructor*/
		x=a;
		y=b;
	}
	maths(int a){
		x=a;
		y=0;
	}
	maths(maths m){
		x=m.x;
		y=m.y;
	}
	maths(){
		x=500;
		y=100;
	}
}

class constructoroverloading{
	public static void main (String args[]){
		maths m1 = new maths(50,30);
		maths m2 = new maths(30);
		maths m3 = new maths(m1);
		maths m4 = new maths();
		System.out.println("Sum 1 = "+m1.add());
		System.out.println("Substraction 1 = "+m1.sub());
		System.out.println("Sum 2 = "+m2.add());
		System.out.println("Substraction 2 = "+m2.sub());
		System.out.println("Sum 3 = "+m3.add());
		System.out.println("Substraction 3 = "+m3.sub());
		System.out.println("Sum 4 = "+m4.add());
		System.out.println("Substraction 4 = "+m4.sub());
	}

}
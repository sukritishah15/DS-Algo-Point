package Java.Algorithms;

public class Mycalc {
		
	    public static void main(String args[]){

	        String exp1="78+5sin60+8(6cos60+5)";
	        String exp2="log50+tan15";
	        System.out.println(gunnercal(exp2));
		//Contributed by Ajiri Gunn
                //Sample input: gunnercal("2+3(cos(35+5^2)+log10)")
                //Sample output: "6.5"
		//Time complexity O(n):linear
		//Space complexity O(n):linear
	    }
	    
		//A recursive function to compute brackets and replace as number
	    public static String brackets(String bracketinput,int i){//to be used in a loop
	        String anstring="";
	        String answer="";
	        String ans="";
	        String temp="";
	        int k=i+1;
	        int bend=0;
	        temp=simplificationb(bracketinput);
	        bracketinput=temp;
	        temp="";
	        while ((k<bracketinput.length())&&(bracketinput.charAt(k)!=')')){

	            if(bracketinput.charAt(k)=='('){//recursion
	                ans=brackets(bracketinput,k);
	                bend=bracketendex(bracketinput,k);
	                //bracketinput.replaceFirst(bracketinput.substring(k,bend), ans);
	                //temp=bracketinput.substring((i+1),k)+ans+bracketinput.substring(bend+1);
	                anstring+=ans;
	                k=bend+1;
	                continue;
	            }

	            anstring+=bracketinput.charAt(k);
	            k++;

	        }
	        bracketinput=anstring;
	        anstring = simplification1(bracketinput);
	        answer = EP(anstring);
	        anstring = simplification1(answer);
	        answer = simplification1(anstring);
	        anstring = transtrigcomputation(answer);
	        answer = simplification1(anstring);
	        anstring = exponent(answer);
	        answer = simplification1(anstring);
	        anstring = squareroot(answer);
	        answer = simplification1(anstring);
	        anstring = of(answer);
	        answer = simplification1(anstring);

	        anstring = division(answer);
	        answer = simplification1(anstring);

	        anstring = multiplication(answer);
	        answer = simplification1(anstring);

	        anstring = addition(answer);
	        answer = simplification1(anstring);

	        anstring = subtraction(answer);
	        answer = simplification1(anstring);

	        anstring=answer;

	        if (anstring.startsWith("+"))
	            return anstring.substring(1);
	        else
	            return anstring;
	    }
	    //registers all number characters
	    public static Boolean numcon(char i){

	        Boolean numcond=(i=='3'||i=='1'||i=='2'||i=='4'||i=='5'||i=='6'||i=='7'||i=='8'||i=='9'||i=='0'||i=='.');
	        return(numcond);

	    }
	    //places "*" symbol if number or bracket comes before a bracket
	    public  static String simplificationb(String bracketinput){
	        int k=0,count=0;
	        String temp="";
	        temp=bracketinput.replaceAll("\\)\\^", "\\)x");
	        bracketinput


	                =temp;
	        while ((k<bracketinput.length())&&((k+1)<bracketinput.length())){
	            if (numcondition(bracketinput.charAt(k))&&(bracketinput.charAt(k+1)=='(')){
	                temp=bracketinput.substring(0,(k+1))+"o"+bracketinput.substring(k+1);
	                count++;
	            }else if(bracketinput.charAt(k)==')'&&numcon(bracketinput.charAt(k+1))){
	                temp=bracketinput.substring(0,(k+1))+"o"+bracketinput.substring(k+1);
	                count++;
	            }else if(bracketinput.charAt(k)==')'&&(!operators(bracketinput.charAt(k+1)))){
	                temp=bracketinput.substring(0,(k+1))+"o"+bracketinput.substring(k+1);
	                count++;
	            }else if((!operators(bracketinput.charAt(k))&&(bracketinput.charAt(k)!='\u221A'&&bracketinput.charAt(k)!='\u221B'))&&(bracketinput.charAt(k+1)=='(')){
	                temp=bracketinput.substring(0,(k+1))+"o"+bracketinput.substring(k+1);
	                count++;
	            }else if((bracketinput.charAt(k)==')')&&(bracketinput.charAt(k+1)=='(')){
	                temp=bracketinput.substring(0,(k+1))+"o"+bracketinput.substring(k+1);
	                count++;
	            }
	            if((count>0)&&(bracketinput!=temp)){
	                bracketinput=simplification1(temp);
	            }
	            k++;
	        }
	        return bracketinput;
	    }
	    //gets the index of the relevant end bracket
	    public static int bracketendex(String bracketinput,int i){//to be used in a loop
	        String anstring="";
	        String answer="";
	        int k=i+1;
	        int countb=1;
	        while (true){

	            if (bracketinput.charAt(k)=='(')
	                countb++;
	            if(bracketinput.charAt(k)==')')
	                countb--;
	            if (countb==0)
	                break;
	            k++;

	        }

	        /*while (k<bracketinput.length()){
	            if (bracketinput.charAt(k)==')')
	                countb--;
	            if (countb==0)
	                break;
	            k++;
	        }*/
	        return k;
	    }
	    //registers absolutely all operators
	    public  static boolean operators(char i){
	        boolean b=(i=='o'||i=='x'||i=='!'||i=='*'||i=='/'||i=='+'||i=='-'||i=='S'||i=='C'||i=='T'||i=='s'||i=='c'||i=='t'||i=='n'||i=='a'||i=='l'||i=='e'||i=='('||i==')'||i=='^');
	        return b;
	    }
	    //cracker operators
	    public  static boolean coperators(char i){
	        boolean b=(i=='o'||i=='x'||i=='!'||i=='*'||i=='/'||i=='S'||i=='C'||i=='T'||i=='s'||i=='c'||i=='t'||i=='n'||i=='a'||i=='l'||i=='e'||i=='('||i==')'||i=='^');
	        return b;
	    }
	    //computes all divisions in input string
	    public static String division(String input){
	        double num1=0,num2=0,ans=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0;

	        while (b<input.length()){
	            if (input.charAt(b)=='/'){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                ans=num1/num2;
	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                b=1;
	                count++;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            b++;
	        }
	        return input;
	    }

	    //computes all transcedental and trigonometric functions
	    public static String transtrigcomputation(String input){
	        double num2=0;
	        double ans=0;
	        double answer=0;
	        int k=0,t1=0,t2=0;
	        String anstring="",temp="";
	        int i=0;
	        int count=0;
	        temp=transtrigcorrection(input);
	        input=temp;
	        temp="";
	        while (i<input.length()){


	            if (input.charAt(i)=='S'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.sin(num2*Math.PI/180);
	                k=getfrontex(input,(i+1));

	                if(answer>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(answer);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }

	            if (input.charAt(i)=='C'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.cos(num2*Math.PI/180);
	                k=getfrontex(input,(i+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='T'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.tan(Math.toRadians(num2));
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(ans);
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='e'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.exp(num2);
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(Math.abs(ans));
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='t'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.atan(num2)*180/Math.PI;
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(Math.abs(ans));
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='s'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.asin(num2)*180/Math.PI;
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(Math.abs(ans));
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='c'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.toDegrees(Math.acos(num2));
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(Math.abs(ans));
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='n'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.log(num2);
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(Math.abs(ans));
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }
	            if (input.charAt(i)=='l'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.log10(num2);
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(Math.abs(ans));
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }

	            if(input.charAt(i)=='a'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.pow(10,num2);
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(ans);
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }
	            }

	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	                //temp="";
	            }

	            i++;
	        }

	        return input;
	    }
	    public static String multiplication(String input){
	        double num1=0,num2=0,ans=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0;
	        while (b<input.length()){
	            if (input.charAt(b)=='*'){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                ans=num1*num2;
	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	                b=1;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            b++;
	        }
	        return input;
	    }
	    public static String of(String input){
	        double num1=0,num2=0,ans=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0;
	        while (b<input.length()){
	            if (input.charAt(b)=='o'){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                ans=num1*num2;
	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	                b=1;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            b++;
	        }
	        return input;
	    }
	    //computes all raised to power operators"^"
	    public static String exponent(String input){
	        double num1=0,num2=0,ans=0,root=0,invp=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0,x=0;

	        while (b<input.length()){//this block occurs in case the negative sign before the number has to be accounted for i.e (-2)^2
	            if (input.charAt(b)=='x'){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                if((num1<0)&&(num2<1)){//this computes the roots of numbers unaccounted for by Math.pow
	                    invp=1/num2;
	                    root=0;
	                    x=1;
	                    while (Math.pow(root,invp)!=num1){
	                        if(Math.pow(root,invp)<num1){
	                            root+=x;
	                            x/=10;

	                        }else{
	                            root-=x;
	                        }
	                    }
	                    ans=root;
	                }else{//normal Math.pow
	                    ans=Math.pow(num1,num2);
	                }

	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	            }else if(input.charAt(b)=='^'){//normal power computation
	                num1=getbacknum(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                if((num1<0)&&(num2<1)){
	                    invp=1/num2;
	                    root=0;
	                    x=1;
	                    while (Math.pow(root,invp)!=num1){
	                        if(Math.pow(root,invp)<num1){
	                            root+=x;
	                            x/=10;

	                        }else{
	                            root-=x;
	                        }
	                    }
	                    ans=root;
	                }else{
	                    ans=Math.pow(num1,num2);
	                }

	                t1=getend(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            b++;
	        }
	        return input;
	    }
	    //computes all subtractions in input string also had to be called twice in gunnercal
	    public static String addition(String input){
	        double num1=0,num2=0,ans=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0;
	        while (b<input.length()){
	            if ((input.charAt(b)=='+')&&(b>0)){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                ans=num1+num2;
	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	                b=1;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            b++;
	        }
	        return input;
	    }

	    //computes all subtractions in input string: had to be called twice in gunnercal
	    public static String subtraction(String input){
	        double num1=0,num2=0,ans=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0;
	        while (b<input.length()){
	            if ((input.charAt(b)=='-')&&((b>0)&&(input.charAt(b-1)!='E'))){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                ans=num1-num2;
	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	                b=1;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	                // b=1;
	            }
	            b++;
	        }
	        return input;
	    }

	    //gets the index of the last number after an operator
	    public static int getfrontex(String input,int i){

	        input+=" ";
	        int k=i,end=0;
	        while((numcondition(input.charAt(k))||input.charAt(k)=='-')&&(k<(input.length()))){

	            if(input.charAt(k)=='E'){

	                if(input.charAt(k+1)=='+'){
	                    k=getfrontex(input,k+2)+1;
	                }else{

	                    k=getfrontex(input,k+1)+1;
	                }
	                break;
	            }
	            if((input.charAt(k+1)=='-')||(input.charAt(k+1)=='+')){
	                k++;
	                break;

	            }
	            k++;
	        }
	        k--;

	        return(k);
	    }
	    // computes and replaces all n factorial in input string used in simplification1
	    public static String factorial(String input){
	        int m=0,count=0;
	        String facts="",anstring="";
	        while(m<input.length()){//factorial
	            Double num,factorial;
	            factorial=1.0;
	            int endex;

	            if (input.charAt(m)=='!'){

	                endex=getend(input,(m-1));
	                num=getbacknum(input,(m-1));
	                if(num%1>0) {

	                    input = "Error";
	                    break;
	                }
	                for(int t=1;t<=num;t++){

	                    factorial*=t;
	                }
	                anstring=input.replaceFirst(input.substring(endex,(m+1)),String.valueOf(factorial));
	                facts=anstring;
	                count++;
	            }
	            m++;
	            if ((count>0)&&(input!=anstring))
	                input=anstring;
	        }
	        return input;
	    }
	    //primary simplification: replaces all words with symbols and reduces all multiple signs to a single operator
	    public  static String simplification1(String input){
	        int i=0;

	        String answer="",anstring="";
	        //REPLACE trig and transcedental operations



	        anstring=input.replaceAll("Asin", "s");
	        answer=anstring.replaceAll("Acos", "c");
	        anstring=answer.replaceAll("Atan", "t");
	        answer=anstring.replaceAll("sin", "S");
	        anstring=answer.replaceAll("cos", "C");
	        answer=anstring.replaceAll("tan", "T");

	        anstring=answer.replaceAll("Alog", "a");
	        answer=anstring.replaceAll("exp", "e");
	        anstring=answer.replaceAll("ln", "n");
	        answer=anstring.replaceAll("log", "l");

	        anstring=answer.replaceAll("\\+\\+\\+", "\\+");
	        answer=anstring.replaceAll("\\+\\+\\-", "\\-");
	        anstring=answer.replaceAll("\\+\\-\\+", "\\-");
	        answer=anstring.replaceAll("\\-\\+\\+", "\\-");
	        anstring=answer.replaceAll("\\-\\-\\+", "\\+");
	        answer=anstring.replaceAll("\\-\\+\\-", "\\+");
	        anstring=answer.replaceAll("\\+\\-\\-", "\\+");
	        answer=anstring.replaceAll("\\-\\-\\-", "\\-");
	        anstring=answer.replaceAll("\\+\\+", "\\+");
	        answer=anstring.replaceAll("\\+\\-", "\\-");
	        anstring=answer.replaceAll("\\-\\+", "\\-");
	        answer=anstring.replaceAll("\\-\\-", "\\+");
	        anstring=answer.replaceAll("o\\+", "o");
	        answer=anstring.replaceAll("\\*\\+","\\*");
	        anstring=answer.replaceAll("\\/\\+", "\\/");

	        answer=anstring.replaceAll("\u221A\\+","\u221A");
	        anstring=answer.replaceAll("\u221B\\+","\u221B");


	        answer=anstring.replaceAll("E+", "E");
	        anstring=answer;
	        answer=factorial(anstring);

	        input=answer;
	        return input;
	    }
	    //impliments transtrig registers to modify transcedental and trig parts of input in case number comes before them without "*" sign
	    public static String transtrigcorrection(String input){
	        int i=0,k=1;
	        String temp="";
	        int count=0;
	        while (i<input.length()){
	            if (i==(input.length()-1))
	                k=i;
	            if(numcondition(input.charAt(i))&&transtrigsymbolcond(input.charAt(k))){

	                temp=input.substring(0,(i+1))+"o"+input.substring(i+1);
	                count++;

	            }
	            if((count>0)&&(temp!=input))
	                input=simplification1(temp);

	            i++;
	            k++;

	        }
	        return input;
	    }
	    //registers all transtrig symbols
	    public static Boolean transtrigsymbolcond(char i){
	        boolean conditon=(i=='s'||i=='c'||i=='t'||i=='S'||i=='C'||i=='T'||i=='a'||i=='e'||i=='n'||i=='l'||i=='\u221A'||i=='\u03C0');
	        return conditon;
	    }
	    //gets number at the back of operator when negetive number is not relevant
	    public static double getbacknum(String input,int i){

	        input=" "+input;
	        String rnumstring="";
	        String numstring="";
	        int k,count=0;
	        k=i+1;
	        while((numcondition(input.charAt(k)))&&(k>=0)){

	            rnumstring+=input.charAt(k);
	            k--;
	            count++;
	            if ((input.charAt(k)=='-'||input.charAt(k)=='+')&&(input.charAt(k-1)=='E')){

	                if (input.charAt(k)=='-'){
	                    rnumstring+="-"+input.charAt(k-1);
	                }else if(input.charAt(k)=='+'){

	                    rnumstring+="+"+input.charAt(k-1);
	                }
	                k-=2;
	                count+=2;
	            }
	        }
	        count-=1;
	        while (count>=0){
	            numstring+=rnumstring.charAt(count);
	            count--;
	        }
	        return(Double.parseDouble(numstring));
	    }
	    //to get number at the back of operator
	    public static double getbacknumber(String input,int i){

	        input=" "+input;
	        String rnumstring="";
	        String numstring="";
	        double ans=0;
	        int k=i+1,count=0;
	        while(numcondition(input.charAt(k))){

	            rnumstring+=input.charAt(k);
	            k--;
	            count++;
	            if ((input.charAt(k)=='-'||input.charAt(k)=='+')&&(input.charAt(k-1)=='E')){

	                if (input.charAt(k)=='-'){
	                    rnumstring+="-"+input.charAt(k-1);
	                }else if(input.charAt(k)=='+'){

	                    rnumstring+="+"+input.charAt(k-1);
	                }
	                k-=2;
	                count+=2;
	            }

	        }

	        count-=1;
	        while (count>=0){
	            numstring+=rnumstring.charAt(count);
	            count--;
	        }
	        if (input.charAt(k)=='-'){
	            ans=((Double.parseDouble(numstring)));
	            ans*=(-1);
	        }else{
	            ans=(Double.parseDouble(numstring));

	        }
	        return ans;

	    }
	    //gets number in front of operator
	    public static Double getfrontnumber(String input,int i){
	        input=input+" ";
	        String numstring="";
	        int k=i;
	        while((numcondition(input.charAt(k))||input.charAt(k)=='-')&&(k<(input.length()))){

	            numstring+=input.charAt(k);
	            if(input.charAt(k)=='E'){

	                if(input.charAt(k+1)=='+'){
	                    numstring+=String.valueOf(getfrontnumber(input,(k+2)).intValue());
	                }else{

	                    numstring+=String.valueOf(getfrontnumber(input,(k+1)).intValue());
	                }
	                break;
	            }
	            if ((input.charAt(k+1)=='-')||(input.charAt(k+1)=='+'))
	                break;
	            k++;
	        }

	        /*if (numstring.startsWith("-")){
	            return((Double.parseDouble(numstring.substring(1)))*(-1));
	        }else
	            return (Double.parseDouble(numstring));*/

	        return Double.parseDouble(numstring);
	    }
	    //gets index of number before operator if negetive numbers are not relevant
	    public static int getend(String input,int i){

	        input=" "+input;
	        String rnumstring="";
	        int end;
	        int k=i+1;
	        while(numcondition(input.charAt(k))){

	            rnumstring+=input.charAt(k);
	            k--;
	            if ((input.charAt(k)=='-'||input.charAt(k)=='+')&&(input.charAt(k-1)=='E')){


	                k-=2;

	            }

	        }
	        end=k;


	        return(end);
	    }
	    //gets back index of numbers before operators if negetive numbers are relevant
	    public static int getendex(String input,int i){

	        input=" "+input;
	        String rnumstring="";
	        int end;
	        int k=i+1;
	        while(numcondition(input.charAt(k))){

	            rnumstring+=input.substring(k, k);
	            k--;

	            if ((input.charAt(k)=='-'||input.charAt(k)=='+')&&(input.charAt(k-1)=='E')){


	                k-=2;

	            }

	        }
	        end=k;

	        if (input.charAt(k)=='-')
	            return(end-1);
	        else
	            return(end);
	    }
	    /**
	     *
	     * @param i
	     * @return
	     */



	    //this function registers all simplified operator symbols
	    public static Boolean numcondition(char i){

	        Boolean numcond=(i=='3'||i=='1'||i=='2'||i=='4'||i=='5'||i=='6'||i=='7'||i=='8'||i=='9'||i=='0'||i=='.'||i=='E');
	        return(numcond);

	    }

	    //supposed to replace all E with 10^num2 not sure if i used it though
	    public static String EP(String input){
	        double num1=0,num2=0,ans=0;
	        int b=0,t1=0,t2=0;
	        String anstring="";
	        String temp="";
	        int count=0;
	        while (b<input.length()){
	            if ((input.charAt(b)=='E')&&(b>0)){
	                num1=getbacknumber(input,(b-1));
	                num2=getfrontnumber(input,(b+1));
	                ans=num1*(Math.pow(10,num2));
	                t1=getendex(input,(b-1));
	                t2=getfrontex(input,(b+1));

	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,t1)+anstring+input.substring(t2+1);
	                }
	                count++;
	            }
	            if((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            b++;
	        }
	        return input;
	    }

	    //replaces all index symbols with proper math statements
	    public static String simplificationp(String input){
	        String answer="",temp="";
	        answer=input.replaceAll("\u00B2","^2");
	        temp=answer.replaceAll("\u00B3","^3");
	        input=temp.replaceAll("\u207B\u00B9","^-1");

	        return input;
	    }

	    //computes square and cube roots if rlevant unicodes appear
	    public static String squareroot(String input){
	        String temp="",anstring="";
	        int i=0,count=0,k=0;
	        double num2=0,ans;
	        temp=simplificationsroot(input);
	        input=temp;
	        temp="";
	        while (i<input.length()){
	            if (input.charAt(i)=='\u221A'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.sqrt(num2);
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(ans);
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }

	            }else if (input.charAt(i)=='\u221B'){
	                count++;
	                num2=getfrontnumber(input,(i+1));
	                ans=Math.cbrt(num2);
	                k=getfrontex(input,(i+1));
	                anstring=String.valueOf(ans);
	                if(ans>=0){
	                    anstring="+"+String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);

	                }else{
	                    anstring=String.valueOf(ans);
	                    temp=input.substring(0,i)+anstring+input.substring(k+1);
	                }

	            }
	            if ((count>0)&&(input!=temp))
	                input=simplification1(temp);
	            i++;
	        }
	        return input;
	    }
	    //this ensures that other simplification functions do not put multiplication symbol in front of the roots
	    public  static String simplificationsroot(String input){

	        int i=0,count=0;
	        String temp="";
	        while ((i+1)<input.length()){

	            if (numcondition(input.charAt(i))&&(input.charAt(i+1)=='\u221A'||input.charAt(i+1)=='\u221B')){
	                temp=input.substring(0,(i+1))+"o"+input.substring(i+1);
	                count++;
	            }
	            if ((count>0)&&(input!=temp)){
	                input=simplification1(temp);
	            }
	            i++;
	        }
	        return input;
	    }
	    //the ultimate function that computes input in BODMAS order and renders all symbols in mathematically acceptable form

	    public static String gunnercal(String input){

	        int t=0,countb=0,endb=0;
	        String answer="",anstring="",temp="";
	        answer=input;
	        input=simplificationp(answer);
	        temp=replacepi((input));
	        input=temp;
	        temp=simplificationb(input);
	        input=temp;
	        temp="";

	        for (int i=0;i<1;i++) {
	            while (t < input.length()) {
	                if (input.charAt(t) == '(') {
	                    temp = brackets(input, t);
	                    endb = bracketendex(input, t);
	                    //input.replaceFirst(input.substring(t,endb), answer);
	                    anstring += temp;
	                    t = endb + 1;
	                    continue;
	                }
	                anstring += input.charAt(t);
	                t++;
	            }
	            input = anstring;
	            anstring = simplification1(input);
	            answer = EP(anstring);
	            anstring = simplification1(answer);
	            answer = simplification1(anstring);
	            anstring = transtrigcomputation(answer);
	            answer = simplification1(anstring);
	            anstring = exponent(answer);
	            answer = simplification1(anstring);
	            anstring = squareroot(answer);
	            answer = simplification1(anstring);
	            anstring = of(answer);

	            answer = simplification1(anstring);
	            anstring = division(answer);

	            answer = simplification1(anstring);
	            anstring = multiplication(answer);
	            answer = simplification1(anstring);

	            anstring = addition(answer);
	            answer = simplification1(anstring);

	            anstring = subtraction(answer);
	            answer = simplification1(anstring);

	            input=answer;
	        }
	        return answer;
	    }
	    public static  String replacepi(String input){//this function puts multiplication symbol before or after pi symbol if user didn't e.g 2pi=2*pi
	        String temp="",anstring="",ans="";
	        int i=0,count=0;
	        while((i+2)<input.length()){//front and back conditions
	            if (operators(input.charAt(i))&&input.charAt(i+1)=='\u03C0'&&operators(input.charAt(i+2))){
	                temp=input.substring(0,(i+1))+String.valueOf(Math.PI)+input.substring(i+2);
	                count++;
	            }else if(operators(input.charAt(i))&&input.charAt(i+1)=='\u03C0'&&numcondition(input.charAt(i+2))){
	                temp=input.substring(0,(i+1))+String.valueOf(Math.PI)+'o'+input.substring(i+2);
	                count++;
	            }else if(numcondition(input.charAt((i)))&&input.charAt(i+1)=='\u03C0'&&operators(input.charAt(i+2))){
	                temp=input.substring(0,(i+1))+"o"+String.valueOf(Math.PI)+input.substring(i+2);
	                count++;
	            }else if(numcondition(input.charAt(i))&&input.charAt(i+1)=='\u03C0'&&numcondition(input.charAt(i+2))){
	                temp=input.substring(0,(i+1))+"o"+String.valueOf(Math.PI)+"o"+input.substring(i+2);
	                count++;
	            }else if(input.matches("\\u03C0")){
	                temp=String.valueOf(Math.PI);
	            }
	            if (count>0&&input!=temp){
	                input=temp;
	            }
	            i++;
	        }
	        i=0;
	        count=0;

	        while((i+1)<input.length()){//front conditions
	            if (operators(input.charAt(i))&&input.charAt(i+1)=='\u03C0'){
	                temp=input.substring(0,(i+1))+String.valueOf(Math.PI);
	                count++;
	            }else if(input.charAt(i)=='\u03C0'&&numcondition(input.charAt(i+1))){
	                temp=input.substring(0,(i))+String.valueOf(Math.PI)+'o'+input.substring(i+1);
	                count++;
	            }else if(input.charAt(i)=='\u03C0'&&operators(input.charAt(i+1))){
	                temp=input.substring(0,(i))+String.valueOf(Math.PI)+input.substring(i+1);
	                count++;
	            }else if(numcondition(input.charAt(i))&&input.charAt(i+1)=='\u03C0'){
	                temp=input.substring(0,(i+1))+"o"+String.valueOf(Math.PI);
	                count++;
	            }
	            if (count>0&&input!=temp){
	                input=temp;
	            }
	            i++;
	        }
	        return input;
	    }


	    //thif function needs work
	    public static String[] coeficientformat(String[] input,String variable){
	    
	        String[] patterns=new String[input.length];
	        String temp="";
	        String pattern = null;
	        int y=0;
	        String varsub;
	        for (int h=0;h<input.length;h++){
	        
	            temp=input[h];
	            while(y<temp.length()){
	            
	                if(temp.charAt(y)=='*'||temp.charAt(y)=='/'||temp.substring(y, y).matches(variable)){
	                
	                    pattern+=temp.substring(h,h);
	                   
	                }
	                y++;
	            }
	            temp=pattern;
	            pattern=temp.replaceAll(variable, "2");
	            temp=gunnercal(Simpplificationcheck(pattern.replaceAll("()","(1)")));
	            switch(temp){
	            
	                case "2":
	                    pattern=variable;
	                case "4":
	                    pattern=variable+"^2";
	                case "22":
	                    pattern=variable+"^2";
	                case "8":
	                    pattern=variable+"^3";
	                case "1":
	                    pattern="constant";
	                default :
	                    pattern="unknown";
	            }
	            patterns[h]=pattern;
	        }
	        return patterns;
	    }
	    public static String constantsresolution(String input,String var){
	    
	        String temp="",found="",result="",temp2=input;
	        int front=0,back=0,count=0;
	        String[] res=getTerms(input,var);
	        for (int i=0;i<res.length;i++){
	        
	            temp2=(res[i].startsWith("+")?res[i].substring(1):res[i]);
	           temp=input.replaceFirst(temp2, "+");
	           input=temp;
	        }
	        return input;
	    }
	    public static String Simpplificationcheck(String input){
	    
	        String temp="";
	        temp=input.replaceAll("\\*\\*\\*", "\\*");
	        input=temp.replaceAll("\\*\\*\\/", "\\/");
	        temp=input.replaceAll("\\*\\/\\*", "\\/");
	        input=temp.replaceAll("\\/\\*\\*", "\\/");
	        temp=input.replaceAll("\\*\\*","\\*");
	        input=temp.replaceAll("\\/\\*","\\/");
	        temp=input.replaceAll("\\*\\/", "\\/");
	        if (temp.startsWith("\\/")||temp.startsWith("\\*")){
	        input="1"+temp;
	        }else{
	        input=temp;
	        }
	        temp=(input.endsWith("\\/")||input.endsWith("\\*")?input.substring(0,input.length()-1):input);
	        return temp;
	    }
	    public static String[] coefficientresolution(String[] input,String variable){
	    
	        String[] resolutions=new String[input.length];
	        String temp="";
	        String resolution;
	        for (int t=0;t<input.length;t++){
	        
	            temp=input[t].replaceAll(variable, "(1)");
	            resolution=gunnercal(temp);
	            resolutions[t]=resolution;
	        }
	        return resolutions;
	    }
	  //gets terms with the variable attatched to it and returns String of the terms  
	   public static String[] getTerms(String input ,String var){
	   String result="";
	   String found="";
	   
	       for(int i=0;i<input.length();i++){
	       
	           found=((i+var.length())<input.length()?input.substring(i,(i+var.length())):"");
	           if ((i+var.length())<input.length()&&found.matches(var)){
	           
	               result+=getinTerm(input,i)+",";  
	               //i=getfrontinTex(input,i);
	           }
	       }
	       if(input.endsWith(var)){
	       
	           result+=getinTerm(input,input.lastIndexOf(var))+","; 
	       }
	      String[] res=result.substring(0,result.length()-1).split(",");
	       return(res);
	   }
	   public static int getbackinTex(String input,int i){
	   
	       int res=0;
	       for (int k=i;k>=0;k--){
	       
	           if ((input.charAt(k)=='+'&&!coperators(input.charAt(k-1)))||(input.charAt(k)=='-'&&!coperators(input.charAt(k-1)))){
	           
	              res=k;
	              break;
	           }
	       }
	       return res;
	   }
	   public static int getfrontinTex(String input,int i){
	   
	       int res=input.length();
	       for (int k=i;k<input.length()-1;k++){
	       
	          if ((input.charAt(k)=='+'&&!coperators(input.charAt(k-1)))||(input.charAt(k)=='-'&&!coperators(input.charAt(k-1)))){
	           
	              res=k;
	              break;
	           }
	       }
	       return res;
	   }
	public static String getinTerm(String input, int i){

	    int front=getfrontinTex(input,i);
	    int back=getbackinTex(input,i);
	    
	    String result=input.substring(back,front);
	    return result;
	}
	

}

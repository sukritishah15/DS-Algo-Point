package SnakeAI;

//this exeption is thrown when there is no path to food and snake hits it self. 
public class snakeHeadTrapException extends Exception {
    @Override
    public void printStackTrace() {
        System.out.println("NO Possible Way");
    }
}

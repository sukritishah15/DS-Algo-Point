package Java.Sorting;

import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.CountDownLatch;

public class SleepSort {

    public static void sleepSort( int[] nums ) {
        final CountDownLatch doneSignal = new CountDownLatch( nums.length );
        Arrays.stream( nums ).forEach( num -> new Thread( () -> {
            doneSignal.countDown();
            try {
                doneSignal.await();
                Thread.sleep( num * 500 ); //Sleeps for num*500 ms
                System.out.print( num + " " );
            } catch ( InterruptedException e ) {
                e.printStackTrace();
            }
        } ).start() );
    }

    public static void main( String[] args ) {

        String numbers;
        Scanner sc = new Scanner( System.in );
        System.out.println( "Please enter the numbers that you want to sort: " );
        numbers = sc.nextLine();

        String[] stringArr = numbers.split( "," );

        int[] nums = new int[ stringArr.length ];
        for ( int i = 0; i < nums.length; i++ ) {
            nums[ i ] = Integer.parseInt( stringArr[ i ] );
        }
        sleepSort( nums );
    }

    /* Sample input: "1,6,2,90,23"
     * Complexity for the sleepSort method : O(NlogN + max(input))
     * Sample output: 1 2 6 23 90
     * Since the input is a dynamic and a list of strings,
     *  it parse integers by commas and time complexity for can be different.
     */

}
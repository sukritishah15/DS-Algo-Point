package Java.DataStructures;

import java.util.*;
import java.io.*;

public class LRTF
{

	//Assumes arrival time is sorted
	public static void schedule(int[] pid,int[] run,int[] arrival) 
	{

		int current_time = arrival[0];
		int count = 0;
		int[] q = new int[100];
		boolean allArrived = false;
		int qcount = 0;

		for(int i=0;i<arrival.length;i++)
		{
			if(arrival[i] == current_time)
			{
				q[qcount] = pid[i];
				qcount++;
				count++;
			}
			else if(arrival[i]>current_time)
				break;
		}

		if(count == arrival.length)
				allArrived = true;

		while(!allArrived || qcount !=0)
		{
			int index = findMax(q, run, count); //index of pidmax
				
			int pidmax = index;
			System.out.println("Chosen PIDMAX: "+pidmax);
			if(!allArrived)
			{
			//air bubble
			if(qcount == 0)
			{
				current_time = arrival[count];
				q[qcount] = pid[count];
				qcount++;
				count++;

				if(count == arrival.length)
					allArrived = true;
				continue;
			}
			if(arrival[count]<(current_time+run[pidmax]))
			{	

				//Check, execute pre-empt if required. Loop back.
				int updated_time = arrival[count];
				q[qcount] = pid[count];
				
				count++;
				qcount++;
				run[pidmax] = run[pidmax] - (updated_time - current_time);
				current_time = updated_time;
				
				if(count == arrival.length)
					allArrived = true;
				continue;

				
			}

			}
			current_time = current_time+run[pidmax];
			run[pidmax] = 0;

			int i = q[qcount-1];
			q[index] = i;
			qcount--;

			
			System.out.println("Current time: "+current_time);			
		}
	}

	public static int findMax(int q[],int run[], int count)
	{
		int index = -1;
		int max = 0;
		
		for(int i=0;i<count;i++)
		{
			if(run[i]!=0 && run[i]>max)
			{
				max = run[i];
				index = i;
			}
		}	

		return index;
	}

	//PID has to be 0,1,2..
	public static void main(String args[])
	{

		int arrival[]=new int[] {0,1,2,3};
        int run[]=new int[] {5,2,3,1}; 
        int pid[] = new int[]{0,1,2,3};
  		schedule(pid, run, arrival);

	}
}

// OUTPUT
// Chosen PIDMAX: 0
// Chosen PIDMAX: 0
// Chosen PIDMAX: 0
// Chosen PIDMAX: 2
// Current time: 6
// Chosen PIDMAX: 0
// Current time: 8
// Chosen PIDMAX: 1
// Current time: 10
// Chosen PIDMAX: 3
// Current time: 11
// .
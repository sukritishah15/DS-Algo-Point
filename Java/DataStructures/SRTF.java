package Java.DataStructures;

import java.util.*;
import java.io.*;

public class SRTF
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
			int index = findMin(q, run, count); //index of pidmin
				
			int pidmin = index;
			if (pidmin == -1)
				System.out.println("Chosen PROCESSID: none");
			else
				System.out.println("Chosen PROCESSID: "+pidmin);

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
			if(arrival[count]<(current_time+run[pidmin]))
			{	

				//Check, execute pre-empt if required. Loop back.
				int updated_time = arrival[count];
				q[qcount] = pid[count];
				
				count++;
				qcount++;
				run[pidmin] = run[pidmin] - (updated_time - current_time);
				current_time = updated_time;
				
				if(count == arrival.length)
					allArrived = true;
				continue;

				
			}

			}
			current_time = current_time+run[pidmin];
			run[pidmin] = 0;

			int i = q[qcount-1];
			q[index] = i;
			qcount--;

			
			System.out.println("Current time: "+current_time);			
		}
	}

	public static int findMin(int q[],int run[], int count)
	{
		int index = -1;
		int min = 100;
		
		for(int i=0;i<count;i++)
		{
			if(run[i]!=0 && run[i]<min)
			{
				min = run[i];
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
// Chosen PROCESSID: 0
// Chosen PROCESSID: 1
// Chosen PROCESSID: 1
// Current time: 3
// Chosen PROCESSID: 2
// Chosen PROCESSID: 3
// Current time: 4
// Chosen PROCESSID: 2
// Current time: 7
// Chosen PROCESSID: 0
// Current time: 11
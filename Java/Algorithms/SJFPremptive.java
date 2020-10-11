package Java.Algorithms;

/*
 * Copyright 2020 Jinit Jain
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//Java program to implement Shortest Remaining Time First 
//Shortest Remaining Time First (SRTF) 
//Preptive
class Process 
{ 
 int pid; // Process ID 
 int bt; // Burst Time 
 int art; // Arrival Time 
   
 public Process(int pid, int bt, int art) 
 { 
     this.pid = pid; 
     this.bt = bt; 
     this.art = art; 
 } 
}

public class SJFPremptive  
{ 
 // Method to find the waiting time for all 
 // processes 
 static void findWaitingTime(Process proc[], int n, 
                                  int wt[]) 
 { 
     int rt[] = new int[n]; 
    
     // Copy the burst time into rt[] 
     for (int i = 0; i < n; i++) 
         rt[i] = proc[i].bt; 
    
     int complete = 0, t = 0, minm = Integer.MAX_VALUE; 
     int shortest = 0, finish_time; 
     boolean check = false; 
    
     // Process until all processes gets 
     // completed 
     while (complete != n) { 
    
         // Find process with minimum 
         // remaining time among the 
         // processes that arrives till the 
         // current time` 
         for (int j = 0; j < n; j++)  
         { 
             if ((proc[j].art <= t) && 
               (rt[j] < minm) && rt[j] > 0) { 
                 minm = rt[j]; 
                 shortest = j; 
                 check = true; 
             } 
         } 
    
         if (check == false) { 
             t++; 
             continue; 
         } 
    
         // Reduce remaining time by one 
         rt[shortest]--; 
    
         // Update minimum 
         minm = rt[shortest]; 
         if (minm == 0) 
             minm = Integer.MAX_VALUE; 
    
         // If a process gets completely 
         // executed 
         if (rt[shortest] == 0) { 
    
             // Increment complete 
             complete++; 
             check = false; 
    
             // Find finish time of current 
             // process 
             finish_time = t + 1; 
    
             // Calculate waiting time 
             wt[shortest] = finish_time - 
                          proc[shortest].bt - 
                          proc[shortest].art; 
    
             if (wt[shortest] < 0) 
                 wt[shortest] = 0; 
         } 
         // Increment time 
         t++; 
     } 
 } 
    
 // Method to calculate turn around time 
 static void findTurnAroundTime(Process proc[], int n, 
                         int wt[], int tat[]) 
 { 
     // calculating turnaround time by adding 
     // bt[i] + wt[i] 
     for (int i = 0; i < n; i++) 
         tat[i] = proc[i].bt + wt[i]; 
 } 
    
 // Method to calculate average time 
 static void findavgTime(Process proc[], int n) 
 { 
     int wt[] = new int[n], tat[] = new int[n]; 
     int  total_wt = 0, total_tat = 0; 
    
     // Function to find waiting time of all 
     // processes 
     findWaitingTime(proc, n, wt); 
    
     // Function to find turn around time for 
     // all processes 
     findTurnAroundTime(proc, n, wt, tat); 
    
     // Display processes along with all 
     // details 
     System.out.println("Processes " + 
                        " Burst time " + 
                        " Waiting time " + 
                        " Turn around time"); 
    
     // Calculate total waiting time and 
     // total turnaround time 
     for (int i = 0; i < n; i++) { 
         total_wt = total_wt + wt[i]; 
         total_tat = total_tat + tat[i]; 
         System.out.println(" " + proc[i].pid + "\t\t"
                          + proc[i].bt + "\t\t " + wt[i] 
                          + "\t\t" + tat[i]); 
     } 
    
     System.out.println("Average waiting time = " + 
                       (float)total_wt / (float)n); 
     System.out.println("Average turn around time = " + 
                        (float)total_tat / (float)n); 
 } 
   
 // Driver Method 
 public static void main(String[] args) 
 { 
      Process proc[] = { new Process(1, 6, 1),  
                         new Process(2, 8, 1), 
                         new Process(3, 7, 2),  
                         new Process(4, 3, 3)}; 
       
      findavgTime(proc, proc.length); 
 } 
} 


package Java.Algorithms;/*
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
//Java program to implement Shortest Job first with Arrival Time (Non Premptive) 
import java.util.*;

class SJFNonpremptive { 

 static int[][] mat = new int[10][6]; 

 static void arrangeArrival(int num, int[][] mat) { 
     for (int i = 0; i < num; i++) { 
         for (int j = 0; j < num - i - 1; j++) { 
             if (mat[j][1] > mat[j + 1][1]) { 
                 for (int k = 0; k < 5; k++) { 
                     int temp = mat[j][k]; 
                     mat[j][k] = mat[j + 1][k]; 
                     mat[j + 1][k] = temp; 
                 } 
             } 
         } 
     } 
 } 

 static void completionTime(int num, int[][] mat) { 
     int temp, val = -1; 
     mat[0][3] = mat[0][1] + mat[0][2]; 
     mat[0][5] = mat[0][3] - mat[0][1]; 
     mat[0][4] = mat[0][5] - mat[0][2]; 

     for (int i = 1; i < num; i++) { 
         temp = mat[i - 1][3]; 
         int low = mat[i][2]; 
         for (int j = i; j < num; j++) { 
             if (temp >= mat[j][1] && low >= mat[j][2]) { 
                 low = mat[j][2]; 
                 val = j; 
             } 
         } 
         mat[val][3] = temp + mat[val][2]; 
         mat[val][5] = mat[val][3] - mat[val][1]; 
         mat[val][4] = mat[val][5] - mat[val][2]; 
         for (int k = 0; k < 6; k++) { 
             int tem = mat[val][k]; 
             mat[val][k] = mat[i][k]; 
             mat[i][k] = tem; 
         } 
     } 
 } 


 public static void main(String[] args) { 
     int num; 

     Scanner sc = new Scanner(System.in); 

     System.out.println("Enter number of Process: "); 
     num = sc.nextInt(); 

     System.out.println("...Enter the process ID..."); 
     for (int i = 0; i < num; i++) { 
         System.out.println("...Process " + (i + 1) + "..."); 
         System.out.println("Enter Process Id: "); 
         mat[i][0] = sc.nextInt(); 
         System.out.println("Enter Arrival Time: "); 
         mat[i][1] = sc.nextInt(); 
         System.out.println("Enter Burst Time: "); 
         mat[i][2] = sc.nextInt(); 
     } 

     System.out.println("Before Arrange..."); 
     System.out.println("Process ID\tArrival Time\tBurst Time"); 
     for (int i = 0; i < num; i++) { 
         System.out.printf("%d\t\t%d\t\t%d\n",  
             mat[i][0], mat[i][1], mat[i][2]); 
     } 

     arrangeArrival(num, mat); 
     completionTime(num, mat); 
     System.out.println("Final Result..."); 
     System.out.println("Process ID\tArrival Time\tBurst" + 
                     " Time\tWaiting Time\tTurnaround Time"); 
     for (int i = 0; i < num; i++) { 
         System.out.printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",  
          mat[i][0], mat[i][1], mat[i][2], mat[i][4], mat[i][5]); 
     } 
     sc.close(); 
 } 
} 



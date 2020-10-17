package Java.Algorithms;/*
    Input Format:
    First line contains two integers n(number of nodes) and m(number of edges). Each node is
    numbered from 1 to n. Next m lines contains two integers
    u v representing an edge between node u to node v.
    n >= 1, m >= 0

    Output Format:
    Prints lines equal to number of connected components in the graph. Each line contains space separated integers denoting
    nodes in a strongly connected component.

    Sample Input:
    4 4
    1 2
    4 1
    2 3
    3 1

    Sample Output:
    1 2 3
    4

    Explanation:
    There are two strongly connected components in the sample input graph
    First one consists of (1,2,3) and the second contains (4).

    Time Complexity :- O(|E| + |V|) where |E| is number of edges and |V| is number of vertices
    Space Complexity :- O(|V|) where |V| is the number of vertices.
*/


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

import javax.annotation.processing.SupportedAnnotationTypes;

public class Kosaraju {

    private static boolean[] visited;   // To track visited nodes during dfs
    private static Stack<Integer> S;    // To store sink nodes.

    // A helper method for dfs.
    static void explore(ArrayList<Integer>[] adj, Integer u) {
        visited[u] = true;
        ArrayList<Integer> neighbours = adj[u];
        for(Integer v : neighbours) {
            if(!visited[v]) {
                explore(adj, v);
            }
        } 
        S.push(u);  // Push the last post order node to the stack.
    }    

    static void DFS(ArrayList<Integer>[] adj) {
        visited = new boolean[adj.length];
        for(int i = 0; i < adj.length; i++) {
            visited[i] = false;
        }
        S = new Stack<Integer>();
        for(int i = 0; i < adj.length; i++) {
            if(!visited[i]) {
                explore(adj, i);
            }
        }
    }

    // To print the nodes in a strongly connected component starting from the sink node u.
    static void exploreSink(ArrayList<Integer>[] adj, Integer u) {
        visited[u] = true;
        System.out.print(u+1 + " ");
        ArrayList<Integer> neighbours = adj[u];
        for(Integer v : neighbours) {
            if(!visited[v]) {
                exploreSink(adj, v);
            }
        } 
    }

    @SuppressWarnings("unchecked")
    private static ArrayList<Integer>[] reverseGraph(ArrayList<Integer>[] adj) {
        ArrayList<Integer>[] adj_r = (ArrayList<Integer>[]) new ArrayList[adj.length];
        for(int i = 0; i < adj_r.length; i++) {
            adj_r[i] = new ArrayList<Integer>();
        } 
        for(int u = 0; u < adj.length; u++) {
            for(Integer v: adj[u]) {
                adj_r[v].add(u);
            }
        }
        return adj_r;
    }

     static void kosaraju(ArrayList<Integer>[] adj) {
        ArrayList<Integer>[] adj_r = reverseGraph(adj);
        DFS(adj_r);
        for(int i = 0; i < adj.length; i++) {   // resusing the visited array.
            visited[i] = false;
        }
        while(!S.empty()) {     // Pop sink nodes one by one and print the nodes.
            Integer u = S.pop();
            if(!visited[u]) {
                exploreSink(adj, u);
                System.out.println();
            }
        }
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
        }
        scanner.close();
        kosaraju(adj);
    }
}

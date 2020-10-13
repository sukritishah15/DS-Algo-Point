package Java.Algorithms;

import java.util.Arrays;


/**
 * @author Nilesh Teji
 * 
 * 
 *    The input will be in the form of Graph a G[i][j] suggests that there is a connection between i vertext and j vertex 
 *    having a edge weight as the Value of G[i][j]
 *          { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
 *    Output
 *    It will be array which will be having the shortest distance from the source vertex
 *    
 *    TimeComplexity-O(V^2) where v is the number of vertices in the Graph
 *    SpaceComplexity -O(V) 
 */

public class Solution {
    public static void main(String[] args) {
        int graph[][] = new int[][] { 
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
        };

        dijsktra(graph, 0);

        // System.out.println(graph.length + " " + graph[0].length);

    }


    /**
     * 
     * @param distance  this is array which contains the distance from the source to
     *                  i in the array index[i];
     * @param finalized this help is to find the distance of which node is finalized
     * @param length    No of Vertices
     * @return minium node with the distance
     */
    static int findMinium(int[] distance, boolean[] finalized, int length) {

        int min = Integer.MAX_VALUE;
        int answer = 0;

        for (int i = 0; i < length; i++) {
            
            if (!finalized[i] && distance[i] <= min) {
                answer = i;
                min = distance[i];

            }
        }
        return answer;

    }

    static void dijsktra(int[][] graph, int src) {

        // we could use a better data structure for this

        int[] distance = new int[graph.length];
        boolean[] finalized = new boolean[graph.length];

        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(finalized, false);

        distance[src] = 0;

        for(int i =0;i<graph.length;i++){

            /**
             * we will extract the minium value from the non fincalized vertices and make it finalized 
             * 
             */
        int u = findMinium(distance, finalized, graph.length);

        finalized[u] = true;

        // this will undergo every adacent vertex of the u vertex
        // if we use a adjacency list we will be able to remove this loop 
        for (int j = 0; j < graph.length; j++) {

            // Explaination to the if condition
            // the distance of the source to the vertex should be less than the value which
            // is stored in distance array
            // distance of the source should be not be infinity
            // and the destination vertex should not be finalized
            // there should be some connection to the vertex from the source

            if (distance[u]+graph[u][j] < distance[j] && distance[u] != Integer.MAX_VALUE && !finalized[j] && graph[u][j] != 0) {
                distance[j] = graph[u][j]+distance[u];
            }
        }

    }

    for (int e :distance){
        System.out.println(e);
    }
}

}

package Java.Algorithms;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Edge {
    int a, b, c;

    Edge(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

public class Main {
    static int n, m, src;
    static final int INF = (int)1e7;
    static List<Edge> g = new ArrayList<>();
    static List<Integer> dist = new ArrayList<>();

    static void bellmanFord() {
        for (int i = 0; i < n; ++i)
            dist.add(INF);

        dist.set(src, 0);

        for (int i = 1; i < n; ++i) {
            // use a boolean variable to optimize the second for loop
            boolean updates = false;

            for (int j = 0; j < m; ++j) {
                int a = g.get(j).a;
                int b = g.get(j).b;
                int c = g.get(j).c;
                int tmp = dist.get(b);
                dist.set(b, Math.min(dist.get(b), dist.get(a) + c));
                // if no improvements have been made, exit from these loops
                if (dist.get(b) < tmp) updates = true;
            }

            if (!updates) break;
        }

        // check if there is a cycle
        for (int i = 0; i < m; ++i) {
            int a = g.get(i).a;
            int b = g.get(i).b;
            int c = g.get(i).c;

            if (dist.get(b) > dist.get(a)+c) {
                System.out.println("Graph contains negative cycle!");
                return;
            }
        }

        for (int i = 0; i < n; ++i)
            System.out.print(dist.get(i) + " ");

        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        src = in.nextInt();

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            g.add(new Edge(a,b, c));
        }

        bellmanFord();
    }
}

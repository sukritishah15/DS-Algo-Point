package Java.Algorithms;/*  Created in the IntelliJ IDEA.
    Copyright(c) 2020
    Created by 0utplay | Aldin Sijamhodzic
    Datum: 04.10.2020
    Uhrzeit: 16:51
*/

public class Maze {

    final int mazeSize, startX, startZ, endX, endZ;
    static int[][] mazeLayout;
    int[][] solution;

    public Maze(int mazeSize, int startX, int startZ, int endX, int endZ) {
        this.mazeSize = mazeSize;
        this.startX = startX;
        this.startZ = startZ;
        this.endX = endX;
        this.endZ = endZ;
    }

    public Maze(int mazeSize) {
        this(mazeSize, 0, 0, mazeSize - 1, mazeSize - 1);
    }

    public Maze(int[][] mazeLayout) {
        this(mazeLayout.length);
    }

    public void solve() {
        solution = new int[mazeSize][mazeSize];
        if (this.isNoValidPoint(this.startX, this.startZ)) {
            System.out.println("No valid start found.");
            return;
        }
        if (this.isNoValidPoint(this.endX, this.endZ)) {
            System.out.println("No valid end found.");
            return;
        }
        if (this.findNext(this.startX, this.startZ)) {
            for (int i = 0; i < this.mazeSize; i++) {
                for (int j = 0; j < this.mazeSize; j++) {
                    char c = 'A';
                    if (this.solution[i][j] == 1) {
                        c = '#';
                    }
                    System.out.print(" " + c + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("No solution found.");
        }

    }

    public boolean findNext(int x, int z) {
        if (x == this.endX && z == this.endZ) {
            this.solution[x][z] = 1;
            return true;
        }
        if (this.isNoValidPoint(x, z)) {
            return false;
        }
        solution[x][z] = 1;
        if (this.findNext(x + 1, z)) {
            return true;
        }
        if (this.findNext(x, z + 1)) {
            return true;
        }
        solution[x][z] = 0;
        return false;
    }

    public boolean isNoValidPoint(int x, int z) {
        return x < 0 || z < 0
                || x >= this.mazeSize || z >= this.mazeSize
                || mazeLayout[x][z] != 1;
    }

    public static void main(String[] args) {
        mazeLayout = new int[][]{
                {1, 1, 1, 1},
                {0, 1, 0, 1},
                {1, 1, 0, 1},
                {1, 0, 0, 1}
        };
        Maze maze = new Maze(mazeLayout);
        maze.solve();
    }
}
/*
Sample I/O
Change the mazeLayout (use 1 for possible paths)

Input:
 {1, 1, 1, 1},
 {0, 1, 0, 1},
 {1, 1, 0, 1},
 {1, 0, 0, 1}
Output:
 #  #  #  #
 A  A  A  #
 A  A  A  #
 A  A  A  #

Time complexity: O(2^(n^2))
Space complexity: O(n^2)

 */

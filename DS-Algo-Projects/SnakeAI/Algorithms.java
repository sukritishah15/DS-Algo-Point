package SnakeAI;
import static SnakeAI.Main.*;

import java.util.*;


//pathfinding algorithms

public class Algorithms {

    public static ArrayList<Node> BFS(Node snakeHead , Node food){
        Queue<Node> queue = new LinkedList<>();
        HashSet<Node> visited = new HashSet<>();
        ArrayList<Node> result = new ArrayList<>();
        setParentNull();
        queue.add(snakeHead);
        while (!queue.isEmpty()) {
            var current = queue.remove();
            BFSHelper(current, queue , result , visited , food);
        }
        return result;
    }

    private static void BFSHelper(Node node, Queue<Node> queue, ArrayList<Node> result , HashSet<Node> visited , Node food) {

        if (visited.contains(node))
            return;

        if (equal(node,food)) {
            getPath(result,node);
            queue.clear();
            visited.clear();
            return;
        }

        visited.add(node);

        ArrayList<Node> list = getChildren(node);

        for (var child : list) {
            if (child.getParent() == null) {
                child.setParent(node);
            }
            queue.add(child);
        }
    }

    private static void getPath(ArrayList<Node> result , Node node) {
        ArrayList<Node> temp = new ArrayList<>();
        while (node != null){
            temp.add(node);
            node = node.getParent();
        }
        for(int i = temp.size() - 1 ; i >= 0 ; i--){
            result.add(temp.get(i));
        }
    }

    public static void setParentNull() {
        for(var a : board){
            for(var b : a){
                b.setParent(null);
                b.setF(0);
                b.setG(0);
                b.setH(0);
            }
        }
    }

    public static boolean equal(Node node, Node food) {
        return node.getX() == food.getX() && node.getY() == food.getY();
    }

    public static ArrayList<Node> getChildren(Node current) {

        ArrayList<Node> ans = new ArrayList<>();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((j == 0 && i == 0)|| (i == -1 && j == -1) || (i == -1 && j == 1) || (i == 1 && j == -1) || (i == 1 && j == 1))
                    continue;

                int dx = current.getX() + i;
                int dy = current.getY() + j;

                if (dx < 0 || dy < 0 || dx > height - 1 || dy > width - 1 || snakeTail.contains(board[dx][dy]))
                    continue;

                ans.add(board[dx][dy]);

            }
        }

        return ans;
    }

    public static ArrayList<Node> Astar(Node snakeHead , Node food) {

        ArrayList<Node> open = new ArrayList<>();

        HashSet<Node> close = new HashSet<>();

        ArrayList<Node> result = new ArrayList<>();

        setParentNull();

        open.add(board[snakeHead.getX()][snakeHead.getY()]);

        while (!open.isEmpty()) {
            var current = open.get(0);
            close.add(current);
            open.remove(current);
            f.repaint();
            if (equal(current,food)) {
                getPath(result,current);
                return result;
            }

            ArrayList<Node> Children = getChildren(current);

            for (var child : Children) {

                if (close.contains(child))
                    continue;

                child.setG(current.getG() + 1);
                child.setH(getDis(child));

                double tempF = child.getG() + child.getH();

                if(open.contains(child) && child.getF() > tempF) {
                    child.setF(tempF);
                    child.setParent(current);
                }
                else if(!open.contains(child)){
                    child.setF(tempF);
                    open.add(child);
                    child.setParent(current);
                }
            }
            open.sort(Comparator.comparingDouble(Node::getF));
        }
        return result;
    }

    private static double getDis(Node node) {

        double xd = (food.getX() - node.getX());

        double yd = (food.getY() - node.getY());

        return Math.sqrt((xd * xd) + (yd * yd));

    }

}

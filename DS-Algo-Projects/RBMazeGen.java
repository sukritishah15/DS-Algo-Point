// Implemented by AmanParmar-git(https://github.com/AmanParmar-git)
// wikipedia (https://en.wikipedia.org/wiki/Maze_generation_algorithm#Recursive_implementation)
// demo video (https://www.youtube.com/watch?v=KkPT9OIduc8)


import javax.swing.*;
import java.awt.*;
import java.util.*;

public class RBMazeGen {

    //you can change this 3 variables to change rect size and width,height of frame.
    //choose specific values for width and height of frame so that divison by rectsize ends with reminder zero, else it will throw arrayoutofbound exeption. 
    private static final int RectSize = 20 , fheight = 1800 , fwidth = 800;
    //you can control speed with this.
    private static final int delay = 10;


    private static int h,w;
    private static Node[][] arr;
    private static JFrame f;
    private static Random random;
    private static Set<Node> visited , currently;

    public static void main(String[] args) {
        f = new JFrame();
        random = new Random();
        f.setSize(fheight,fwidth);
        h = f.getHeight() - 40;
        w = f.getWidth() - 20;
        arr = new Node[w/RectSize][h/RectSize];
        for(int i = 0; i < w /RectSize; i++){
            for(int j = 0; j < h/RectSize ; j++){
                arr[i][j] = new Node(i,j,true,true,true,true);
            }
        }

        visited = new HashSet<>();
        currently = new HashSet<>();

        Canvas canvas = new Canvas();
        f.add(canvas);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);

     new Thread(() -> {
           try {
                  stackMaze();
               } catch (InterruptedException interruptedException) {
                     interruptedException.printStackTrace();
               }
         }).start();
    }

     static void stackMaze() throws InterruptedException {
        Stack<Node> stack = new Stack<>();

        stack.push(arr[0][0]);
        visited.add(arr[0][0]);

        while (!stack.isEmpty()){

            var current = stack.pop();
            currently.add(current);
            f.repaint();
            Thread.sleep(delay);

            ArrayList<Node> children = getChildren(current);
            if(children.size() == 0) {
                currently.remove(current);
                continue;
            }

            stack.push(current);


            int childindex = random.nextInt(children.size());

            var child = children.get(childindex);

            removeWall(child,current);

            visited.add(child);
            stack.push(child);


        }
        currently.clear();
        f.repaint();
    }

     static void removeWall(Node child, Node current) throws InterruptedException {

        int x = child.getX() - current.getX();
        int y = child.getY() - current.getY();

        if(y > 0)
        {
            child.setHasTop(false);
            current.setHasBottom(false);
        }

        else if(y < 0){
            child.setHasBottom(false);
            current.setHasTop(false);
        }

        else if(x > 0){
            child.setHasLeft(false);
            current.setHasRight(false);
        }
        else if(x < 0){
            child.setHasRight(false);
            current.setHasLeft(false);
        }

            Thread.sleep(delay);
        currently.remove(current);

        f.repaint();
    }


     static ArrayList<Node> getChildren(Node current) {

        ArrayList<Node> ans = new ArrayList<>();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                    if ((j == 0 && i == 0) || (i == -1 && j == -1) || (i == -1 && j == 1) || (i == 1 && j == -1) || (i == 1 && j == 1))
                        continue;
                int dx = current.getX() + i;
                int dy = current.getY() + j;


                if (dx < 0 || dy < 0 || dx > arr.length - 1 || dy > arr[0].length - 1) {
                    continue;
                }
                if(!visited.contains(arr[dx][dy]))
                ans.add(arr[dx][dy]);

            }
        }
        return ans;
    }

    static class Canvas extends JComponent{
		
		@Override
        public void paint(Graphics g2) {
            Graphics2D g = (Graphics2D) g2;
            g.setStroke(new BasicStroke(2));
            for(int i = 1; i < w ; i+=RectSize){
                for(int j = 1; j < h ; j+=RectSize){
                    if(currently.contains(arr[i/RectSize][j/RectSize])) {
                        g.setColor(Color.green);
                        g.fillRect(i, j, RectSize, RectSize);
                    }
                    else if(visited.contains(arr[i/RectSize][j/RectSize]))
                    {
                        g.setColor(Color.WHITE);
                        if(arr[i/RectSize][j/RectSize].isHasTop())
                            g.drawLine(i,j,i+RectSize,j);
                        if(arr[i/RectSize][j/RectSize].isHasRight())
                            g.drawLine(i+RectSize,j,i+RectSize,j+RectSize);
                        if(arr[i/RectSize][j/RectSize].isHasBottom())
                            g.drawLine(i,j+RectSize,i+RectSize,j+RectSize);
                        if(arr[i/RectSize][j/RectSize].isHasLeft())
                            g.drawLine(i,j,i,j+RectSize);

                        g.setColor(Color.BLACK);
                        g.fillRect(i,j,RectSize,RectSize);
                    }
                }
            }
        }
    }


static class Node {

    private int x;
    private int y;
    private boolean hasTop , hasRight , hasBottom , hasLeft;

    public Node(int x, int y, boolean hasTop, boolean hasRight, boolean hasBottom, boolean hasLeft) {
        this.x = x;
        this.y = y;
        this.hasTop = hasTop;
        this.hasRight = hasRight;
        this.hasBottom = hasBottom;
        this.hasLeft = hasLeft;
    }


    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }


    public boolean isHasTop() {
        return hasTop;
    }

    public void setHasTop(boolean hasTop) {
        this.hasTop = hasTop;
    }

    public boolean isHasRight() {
        return hasRight;
    }

    public void setHasRight(boolean hasRight) {
        this.hasRight = hasRight;
    }

    public boolean isHasBottom() {
        return hasBottom;
    }

    public void setHasBottom(boolean hasBottom) {
        this.hasBottom = hasBottom;
    }

    public boolean isHasLeft() {
        return hasLeft;
    }

    public void setHasLeft(boolean hasLeft) {
        this.hasLeft = hasLeft;
    }

    @Override
    public String toString() {
        return x + " " + y;
    }
}



}


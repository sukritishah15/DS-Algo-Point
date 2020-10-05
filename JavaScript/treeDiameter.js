class Node {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class Tree {
    constructor() {
        this.root = null;
    }

    insert = (root, val) => {
        if (!root) {
            root = new Node(val);
            return root;
        } else {
            if (val < root.val) {
                if (!root.left) {
                    root.left = new Node(val);
                } else {
                    this.insert(root.left, val);
                }
            } else if (val > root.val) {
                if (!root.right) {
                    root.right = new Node(val);
                } else {
                    this.insert(root.right, val);
                }
            }
            return root;
        }
    }

    findDiameter = root => {
        if (!root) return 0;
        return Math.max(1 + this.findHeight(root.left) + this.findHeight(root.right), this.findDiameter(root.left), this.findDiameter(root.right));
    }

    findHeight = root => {
        if (!root) return 0;
        return 1 + Math.max(this.findHeight(root.left), this.findHeight(root.right));
    }
}

const tree = new Tree();
let root = tree.root;
root = tree.insert(root, 10);
root = tree.insert(root, 4);
root = tree.insert(root, 14);
root = tree.insert(root, 12);
root = tree.insert(root, 11);
root = tree.insert(root, 7);
root = tree.insert(root, 6);
root = tree.insert(root, 8);
root = tree.insert(root, 1);
root = tree.insert(root, 9);

console.log('Diamter of given tree: ' + tree.findDiameter(root));

/*
*  Example
*
*                10
*         4             14
*       1   7         12
*         6   8     11
*               9 
*
* for above tree, diameter is the path from 9 to 11 ( 9-8-7-5-10-14-12-11)
*/
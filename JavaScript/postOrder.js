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

    insert = val => {
        let root = new Node(val);
        return root;
    }

    postOrder = root => {
        if (root) {
            this.postOrder(root.left);
            this.postOrder(root.right);
            console.log(root.val);
        }
    }
}

const tree = new Tree();
let root = tree.root;
root = tree.insert(10);
root.left = tree.insert(4);
root.right = tree.insert(14);
root.right.left = tree.insert(12);
root.right.left.left = tree.insert(11);
root.left.right = tree.insert(7);
root.left.right.left = tree.insert(6);
root.left.right.right = tree.insert(8);
root.left.left = tree.insert(1);
root.left.right.right.right = tree.insert(9);

tree.postOrder(root);

/*
*  Example
*
*                10
*         4             14
*       1   7         12
*         6   8     11
*               9 
*
* for above tree, postorder is 1 6 9 8 7 4 11 12 14 10
*/
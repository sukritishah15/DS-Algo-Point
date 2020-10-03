const util = require("util"); /* if you are using this in browser ,this line will not work ,
                                run it with node or comment out this line and inspectTrie method. 
                                */
function Trie() {
  const root = new Node(null);

  this.addWord = function (word = "") {
    //insert  method in most resources
    if (word === "") return;
    let current = root;
    for (let i = 0; i < word.length; i++) {
      let char = word.charAt(i);
      let index = getIndex(current.children, char);
      if (index === -1) {
        if (i === word.length - 1) {
          current.children.push(new Node(char, true));
        } else {
          current.children.push(new Node(char));
        }
        current = current.children[current.children.length - 1];
      } else {
        if (i === word.length - 1) {
          current.children[index].isEnd = true;
        } else {
          current = current.children[index];
        }
      }
    }
  };

  this.containsWord = function (word) {
    //search method in most resources
    let current = getLastChar(word);
    if (current) return current.isEnd;
    return false;
  };

  this.inspectTrie = function () {
    return util.inspect(root, false, null, true);
  };

  this.didYouMean = function (word) {
    //startsWith method in most resources
    const result = [];
    let current = getLastChar(word);

    getWords(result, current, word);

    return result;
  };

  this.removeWord = function (word) {
    const nodes = [];
    let current = getLastChar(word, nodes);
    if (!current) return;
    current.isEnd = false;

    if (current.children.length === 0) {
      for (let i = nodes.length - 1; i > 0; i--) {
        if (!nodes[i].isEnd) {
          let index = getIndex(nodes[i - 1].children, nodes[i].val);
          nodes[i - 1].children.splice(index, 1);
        } else {
          return;
        }
      }
    }
  };

  //helper methods
  function getLastChar(word, nodes) {
    let current = root;
    for (let i = 0; i < word.length; i++) {
      const char = word.charAt(i);
      const index = getIndex(current.children, char);
      if (index === -1) {
        return;
      }
      if (nodes) nodes.push(current);
      current = current.children[index];
    }
    return current;
  }

  function getWords(result, current, word) {
    for (let i = 0; i < current.children.length; i++) {
      if (current.children[i].isEnd) {
        result.push(word + current.children[i].val);
      }
      if (current.children[i].children.length > 0) {
        getWords(result, current.children[i], word + current.children[i].val);
      }
    }
  }

  function getIndex(array, char) {
    for (let i = 0; i < array.length; i++) {
      let query = array[i].val;
      if (query === char) return i;
    }
    return -1;
  }
}

class Node {
  constructor(val, isEnd = false) {
    this.val = val;
    this.isEnd = isEnd;
    this.children = [];
  }
}

let t = new Trie();

t.addWord("abcd");
t.addWord("ab");
t.addWord("abcdef");

console.log(t.didYouMean("ab"));

t.addWord("abc");
t.removeWord("abcd");

console.log(t.didYouMean("ab"));

console.log(t.containsWord("abcd"));
console.log(t.containsWord("abc"));

console.log(t.inspectTrie());

/*
sample input and output: 

adding three words 'abcd','ab','abcdef'

autocompleting with 'ab' = [ 'abcd', 'abcdef' ]

adding word 'abc'
removing word 'abcd'

autocompleting with 'ab' = [ 'abc', 'abcdef' ]

contains word 'abcd' = false
contains word 'abc' = true

current state of Trie(inspectTrie) : 


Node {
  val: null,
  isEnd: false,
  children:
   [ Node {
       val: 'a',
       isEnd: false,
       children:
        [ Node {
            val: 'b',
            isEnd: true,
            children:
             [ Node {
                 val: 'c',
                 isEnd: true,
                 children:
                  [ Node {
                      val: 'd',
                      isEnd: false,
                      children:
                       [ Node {
                           val: 'e',
                           isEnd: false,
                           children: [ Node { val: 'f', isEnd: true, children: [] } ] } ] } ] } ] } ] } ] }
*/

/*
Time complexity
    O(l) , l = length of word : for all operations, also depends on where you are storing trie
 
Space complexity 
    O(l) , l = length of word : for adding a word

*/

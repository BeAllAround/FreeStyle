const {stdout} = require('process');

// n - level determiner
function printTree(tree, n, b){
        n++;
        if(tree == null)
                return false;
        if(b == 1)
                stdout.write(tree.value+'l\n');
        else if(b == 2)
                stdout.write(tree.value+'r\n');
        else if(b == 0)
                stdout.write(tree.value+'\n'); // root
        if(tree.left){
                stdout.write('-'.repeat(n));
                printTree(tree.left, n, 1);
        }
        if(tree.right){
                stdout.write('-'.repeat(n));
                printTree(tree.right, n, 2);
        }


}

// printTree({left: {left: {left: null, right:null, value: 5}, right: {left: null, right: null, value: 8}, value: 7},  right: {left: null, right: {left: null, right: null, value: 12}, value: 11}, value: 9}, 1, 1, 0);
printTree({left: {left: {left: null, right:null, value: 5}, right: {left: null, right: null, value: 8}, value: 7},  right: {left: {left: null, right: null, value: 33}, right: {left: null, right: null, value: 30}, value: 11}, value: 9}, 0, 0);

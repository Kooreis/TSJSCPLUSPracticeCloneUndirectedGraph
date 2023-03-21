```javascript
class Node {
    constructor(val, neighbors) {
        this.val = val === undefined ? 0 : val;
        this.neighbors = neighbors === undefined ? [] : neighbors;
    }
}

function cloneGraph(node) {
    if (!node) return node;
    const map = new Map();
    return clone(node);

    function clone(node) {
        if (!map.has(node)) {
            const newNode = new Node(node.val);
            map.set(node, newNode);
            newNode.neighbors = node.neighbors.map(clone);
        }
        return map.get(node);
    }
}

const node1 = new Node(1);
const node2 = new Node(2);
const node3 = new Node(3);
const node4 = new Node(4);
node1.neighbors = [node2, node4];
node2.neighbors = [node1, node3];
node3.neighbors = [node2, node4];
node4.neighbors = [node1, node3];

const clonedGraph = cloneGraph(node1);
console.log(clonedGraph);
```
```typescript
class Node {
    val: number;
    neighbors: Node[];

    constructor(val?: number, neighbors?: Node[]) {
        this.val = (val === undefined ? 0 : val);
        this.neighbors = (neighbors === undefined ? [] : neighbors);
    }
}

function cloneGraph(node: Node | null): Node | null {
    if (node == null) {
        return null;
    }

    let map: Map<Node, Node> = new Map();
    let queue: Node[] = [node];

    map.set(node, new Node(node.val));

    while (queue.length > 0) {
        let current: Node = queue.shift() as Node;

        for (let neighbor of current.neighbors) {
            if (!map.has(neighbor)) {
                map.set(neighbor, new Node(neighbor.val));
                queue.push(neighbor);
            }

            map.get(current)?.neighbors.push(map.get(neighbor) as Node);
        }
    }

    return map.get(node) as Node;
}

let node1 = new Node(1);
let node2 = new Node(2);
let node3 = new Node(3);
let node4 = new Node(4);

node1.neighbors = [node2, node4];
node2.neighbors = [node1, node3];
node3.neighbors = [node2, node4];
node4.neighbors = [node1, node3];

let clonedGraph = cloneGraph(node1);
console.log(clonedGraph);
```
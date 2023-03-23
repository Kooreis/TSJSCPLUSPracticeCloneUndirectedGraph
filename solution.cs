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
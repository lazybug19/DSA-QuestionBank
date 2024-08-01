// Tree construction from parent array

struct Node {
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;
    Node() {}

    Node(int x) { data = x; }
};

// Function to construct binary tree from parent array.
Node* createTree(int parent[], int n)
{
    // Create an array to store the reference
    // of all newly created nodes corresponding
    // to node value
    vector<Node*> ref;

    // This root represent the root of the
    // newly constructed tree
    Node* root = new Node();

    // Create n new tree nodes, each having
    // a value from 0 to n-1, and store them
    // in ref
    for (int i = 0; i < n; i++) {
        Node* temp = new Node(i);
        ref.push_back(temp);
    }

    // Traverse the parent array and build the tree
    for (int i = 0; i < n; i++) {

        // If the parent is -1, set the root
        // to the current node having
        // the value i which is stored in ref[i]
        if (parent[i] == -1) {
            root = ref[i];
        }
        else {
            // Check if the parent's left child
            // is NULL then map the left child
            // to its parent.
            if (ref[parent[i]]->left == NULL)
                ref[parent[i]]->left = ref[i];
            else
                ref[parent[i]]->right = ref[i];
        }
    }

    // Return the root of the newly constructed tree
    return root;
}

// Graph as adjacency list

for(int i=0; i<e; i++)
{
	adjList[edges[i][0]] = edges[i][1];
	adjList[edges[i][1]] = edges[i][0];
}

// or
for(auto v: edges)
{
	adjList[v[0]] = v[1];
	adjList[v[1]] = v[0];
}

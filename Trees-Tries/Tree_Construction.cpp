// Tree construction from parent array

class Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int x) 
    { 
	data = x; 
	left = NULL;
	right = NULL;
    }
};

// Function to construct binary tree from parent array.
Node* createTree(int parent[], int n)
{
    vector<Node*> ref;

    // This root represents the root of the
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
	    Node* par = ref[parrent[i]];
            if (par->left == NULL)
                par->left = ref[i];
            else
                par->right = ref[i];
        }
    }

    // Return the root of the newly constructed tree
    return root;
}

// Graph as an adjacency list

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

// Graph from parent array

vector<vector<int>> graph(n);
for(int i=1;i<n;i++)
{
    graph[i].push_back(par[i]);
    graph[par[i]].push_back(i);
}

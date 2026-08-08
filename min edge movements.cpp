class Solution {
  public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    
    int minEdgesReq(int n, vector<vector<int>>& edges) {
    
        // At least (n - 1) edges are needed to connect n nodes
        if ((int)edges.size() < n - 1) {
            return -1;
        }
    
        // Initially every node is its own parent
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    
        // Size of each component
        vector<int> size(n, 1);
    
        for (auto& e : edges) {
            int ru = find(e[0], parent);
            int rv = find(e[1], parent);
    
            // Already in the same component
            if (ru == rv)
                continue;
    
            // Attach the smaller component to the larger one
            if (size[ru] < size[rv])
                swap(ru, rv);
            parent[rv] = ru;
            size[ru] += size[rv];
        }
    
        int components = 0;
        // Count the number of connected components
        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i)
                components++;
        }
    
        // Need (components - 1) edges to connect all components
        return components - 1;
    }

};
//GFG POTD solution for 08 August

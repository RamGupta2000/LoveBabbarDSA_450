class Solution
{
public:
    void dfs(Node *copy, Node *node, vector<Node *> &vis)
    {
        vis[copy->val] = copy;
        for (auto it : node->neighbors)
        {
            if (vis[it->val] == NULL)
            {
                Node *newnode = new Node(it->val);
                (copy->neighbors).push_back(newnode);
                dfs(newnode, it, vis);
            }
            else
            {
                (copy->neighbors).push_back(vis[it->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        Node *copy = new Node(node->val);

        // if( node->neighbors.size() == 0)
        //     return copy;

        vector<Node *> vis(1001, NULL);
        dfs(copy, node, vis);
        return copy;
    }
};
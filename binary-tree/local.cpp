/*  we can get the result using simple recursive traversal
when we recur we cannot just get the result using hd and value of root
so the idea is to pass level in preorder traversal simply incrementing
the level in each recursive call, 
so the map structre would be modified a little bit
 */

 void fillMap(Node *root, map<int, pair<int, int>> &m, int level, int hd) {
    if (root == NULL)
        return;
    
    // decision based on the level
    if (m.count(hd) == 0)
        m[hd] = make_pair(level, root->data);
    else if (m[hd].first <= level)
        m[hd] = make_pair(level, root->data);
    
    fillMap(root->left, m, level+1, hd - 1);
    fillMap(root->right, m, level+1, hd + 1)
}

void bottomView(Node *root)
{
    if (root == NULL)
        return NULL;
    map<int, pair<int, int>> m;
    fillMap(root, m, 0,0);
    //  print the map O(logn)]
    map<int, pair<int, int>>::iterator it;
    for(it = m.begin(); it != m.end(); ++it)
        cout << it->second.second << " ";
}
/*
 * Given a binary tree in which each node element
 * contains a number, find the maximum possible
 * sum from one leaf node to another.
 */

struct Node {
	int data;
	Node *left, *right;
};


int maxSum (Node* root, int &sum) {
    if (root != nullptr) {
        int left = maxSum (root -> left, sum);
        int right = maxSum (root -> right, sum);
        
        if (left == INT_MIN && right == INT_MIN) {
            return root -> data;
        }
        
        if (left != INT_MIN && right != INT_MIN) {
            sum = max(sum, left + right + root -> data);
            return max(left, right) + root -> data;
        }
        
        if (left == INT_MIN)
            return right + root -> data;
        else
            return left + root -> data;
    }
    return INT_MIN;
}


int maxPathSum(Node* root)
{ 
    int sum = INT_MIN;
    maxSum(root, sum);
    return sum;
}

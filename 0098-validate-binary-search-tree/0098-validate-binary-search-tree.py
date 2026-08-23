class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        def validate(node, low, high):
            # Base case: An empty tree is technically a valid BST
            if not node:
                return True
            
            # The current node must fall strictly within the boundaries
            if not (low < node.val < high):
                return False
            
            # Recursively validate left and right subtrees
            # Left child must be less than the current node's value
            # Right child must be greater than the current node's value
            return (validate(node.left, low, node.val) and 
                    validate(node.right, node.val, high))
        
        # Initialize with infinity to encompass all possible node values
        return validate(root, float('-inf'), float('inf'))
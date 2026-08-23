class Solution(object):
    def recoverTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: None Do not return anything, modify root in-place instead.
        """
        self.first = None
        self.second = None
        self.prev = None
        
        def inorder(node):
            if not node:
                return
            
            inorder(node.left)
            
            # If the strict increasing order is violated
            if self.prev and self.prev.val > node.val:
                # The first violation captures the 'prev' node as the first culprit
                if not self.first:
                    self.first = self.prev
                
                # We always update the second culprit to the current 'node'.
                # This perfectly handles both adjacent and non-adjacent swaps.
                self.second = node
                
            self.prev = node
            
            inorder(node.right)
            
        # Execute the traversal to find the two swapped nodes
        inorder(root)
        
        # Swap their values in-place to recover the tree
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val
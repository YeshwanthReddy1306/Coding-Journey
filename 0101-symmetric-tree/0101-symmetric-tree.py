class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if not root:
            return True
        
        return self.isMirror(root.left, root.right)
    
    def isMirror(self, left, right):

        if not left and not right:
            return True
        if not left or not right or left.val != right.val:
            return False
        return self.isMirror(left.left, right.right) and \
               self.isMirror(left.right, right.left)
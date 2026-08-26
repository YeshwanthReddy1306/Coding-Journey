import collections

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        result = []
        queue = collections.deque([root])
        left_to_right = True
        
        while queue:
            level_size = len(queue)
            # Use a deque for O(1) insertions at both ends
            current_level = collections.deque()
            
            for _ in range(level_size):
                node = queue.popleft()
                
                # Append to the right or left based on the current direction
                if left_to_right:
                    current_level.append(node.val)
                else:
                    current_level.appendleft(node.val)
                
                # Standard BFS: add children to the queue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(list(current_level))
            # Toggle the direction for the next level
            left_to_right = not left_to_right
            
        return result
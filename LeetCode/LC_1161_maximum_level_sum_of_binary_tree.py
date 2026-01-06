from collections import defaultdict
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        level_sums = defaultdict(int)

        def traverse(node, lvl):
            if not node:
                return

            level_sums[lvl] += node.val

            traverse(node.left, lvl + 1)
            traverse(node.right, lvl + 1)

        traverse(root, 1)

        max_sum = float("-inf")
        ans_level = 1

        for lvl in sorted(level_sums.keys()):
            if level_sums[lvl] > max_sum:
                max_sum = level_sums[lvl]
                ans_level = lvl

        return ans_level

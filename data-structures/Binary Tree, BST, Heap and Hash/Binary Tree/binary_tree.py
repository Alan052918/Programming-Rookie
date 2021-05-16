class Node:

    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


class BinaryTree:

    def __init__(self):
        self.root = None

    def insertNode(self, key, value):
        if not self:
            self.root = Node(key, value)
            return
        queue = []
        queue.append()

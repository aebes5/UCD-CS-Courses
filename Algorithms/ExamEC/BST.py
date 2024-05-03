import matplotlib.pyplot as plt
import networkx as nx


class Node:
    
  def __init__(self, data, parent): # data, children, parent
    self.data = data
    self.left = None
    self.right = None
    self.parent = parent


class BST:

  def __init__(self):
    self.root = None

  def insert(self, data):
    if self.root is None: # if tree is empty
      self.root = Node(data, None)
    else:
      self._insert(self.root, data)

  def _insert(self, node, data): # recursively call and find correct subtree
    if node.data > data:
      if node.left is None:
        node.left = Node(data, node)
      else:
        self._insert(node.left, data)

    else:
      if node.right is None:
        node.right = Node(data, node)
      else:
        self._insert(node.right, data)

  def delete(self, data):
    if self.root is None: # empty tree
      return
    else:
      node = self.search(data) # find node of data
      if node is not None:
          self.root = self._delete(self.root, node)

  def search(self, data):
    if self.root is None:
      return False
    else:
      return self._search(self.root, data)

  def _search(self, node, data): 
    if node is None:
      return False
    elif node.data == data:
      return node # recursively search, returns the node
    elif node.data > data:
      return self._search(node.left, data)
    else:
      return self._search(node.right, data)

  def _delete(self, root, deletedNode): # generated most by scratch, used chatGPT to 
    if root is None:                    # help check node.parent = None
        return None
  
    if deletedNode.left is None and deletedNode.right is None: # case one simply delete node if no children
        if deletedNode.parent is not None:
            if deletedNode.parent.left == deletedNode:
                deletedNode.parent.left = None
            else:
                deletedNode.parent.right = None
        else:
            root = None
  
    elif deletedNode.left is None or deletedNode.right is None: # case two, one child, swap node with child
        if deletedNode.left is not None:
            if deletedNode.parent is not None:
                if deletedNode.parent.left == deletedNode:
                    deletedNode.parent.left = deletedNode.left
                else:
                    deletedNode.parent.right = deletedNode.left
            else:
                root = deletedNode.left
        else:                                                    
            if deletedNode.parent is not None:
                if deletedNode.parent.left == deletedNode:
                    deletedNode.parent.left = deletedNode.right
                else:
                    deletedNode.parent.right = deletedNode.right
            else:
                root = deletedNode.right
  
    else:   # case three, two children, find the successor and insert in place of deletedNode
        successor = self.searchMinKey(deletedNode.right)
        deletedNode.data = successor.data
        self._delete(deletedNode.right, successor)
  
    return root


  def findSuccessor(self, node): # grabbed from Canvas slides
    succ = None
    if node.right is not None:
      succ = self.searchMinKey(node.right)
    else:
      if node.parent is not None:
        if node == node.parent.left:
          succ = node.parent 
        else:
          node.parent.right = None 
          succ = self.findSuccessor(node.parent)
          node.parent.right = node
    return succ

  def searchMinKey(self, node): # keep checking left subtree to find smallest element
    if node.left is None:
      return node
    else:
      return self.searchMinKey(node.left)

  def display(self): # display/build graph copied from chatGPT for visualization
    G = nx.DiGraph()
    self._build_graph(G, self.root)
    pos = nx.spring_layout(G)
    nx.draw(G,
            pos,
            with_labels=True,
            node_size=1000,
            node_color="lightblue",
            font_size=12,
            font_weight="bold")
    plt.show()

  def _build_graph(self, G, node): # chatGPT
    if node is not None:
      G.add_node(node.data)
      if node.left is not None:
        G.add_edge(node.data, node.left.data)
        self._build_graph(G, node.left)
      if node.right is not None:
        G.add_edge(node.data, node.right.data)
        self._build_graph(G, node.right)

  def traversal(self, type): # driver
    if type == "preorder":
      self._preorder(self.root)
    if type == "inorder":
      self._inorder(self.root)
    if type == "postorder":
      self._postorder(self.root)

  def _preorder(self, node): # parent, left, right
    if node is not None:
      print(node.data)
      self._preorder(node.left)
      self._preorder(node.right)

  def _inorder(self, node): # left, parent, right
    if node is not None:
      self._inorder(node.left)
      print(node.data)
      self._inorder(node.right)

  def _postorder(self, node): # left, right, parent
    if node is not None:
      self._postorder(node.right)
      self._postorder(node.left)
      print(node.data)

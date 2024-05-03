import BST


def main(): # test and output for BST
  arr = [25, 13, 38, 42, 30, 2, 15, 29, 17, 55, 26, 21]

  tree = BST.BST()

  for item in arr:
    tree.insert(item)

  #tree.display()

  print("Preorder:")
  tree.traversal("preorder")
  print("Inorder:")
  tree.traversal("inorder")
  print("Postorder:")
  tree.traversal("postorder")

  tree.insert(10)
  tree.insert(33)
  tree.insert(46)

  tree.delete(26)
  tree.delete(15)
  tree.delete(25)

  succ = tree.findSuccessor(tree.root)
  print(f"Tree.root {tree.root.data} with successor {succ.data}")

  tree.display()

  


if __name__ == "__main__":
  main()

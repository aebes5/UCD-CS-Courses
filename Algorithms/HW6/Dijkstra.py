import Graph as graph
import networkx as nx
import matplotlib.pyplot as plt

# copied from lecture slides
def dijkstra(graph, s):
    visited = {s: 0}
    path = {}
    nodes = set(graph.nodes)

    while nodes: # while remaining nodes
        min_node = None
      
        for node in nodes:
          
            if node in visited:
                if min_node is None:
                    min_node = node 
                elif visited[node] < visited[min_node]:
                    min_node = node
                  
        if min_node is None:
            break
          
        nodes.remove(min_node) # selected
        current_weight = visited[min_node]
        print(f"Node({min_node}) with Weight: {current_weight} is added to the 'Visited' {visited}")
      
        if min_node in graph.edges:
          for v in graph.edges[min_node]:
              weight = current_weight + graph.distances[(min_node, v)] # relaxation
              print(f"    Relaxed: vertex[{v}]: OLD:Infinity, NEW: {weight}, Paths: {path}")
            
              if v not in visited or weight < visited[v]:
                  visited[v] = weight
                  path[v] = min_node
                  print(f"    No edge relaxation is needed for node, {v}")
        else:
          print(f"    No unvisited outgoing edge from node {min_node}")

    return visited, path

# used chatGPT to help me create this graphically
def display_graph(graph):
    nx_graph = nx.Graph()
    for node, neighbors in graph.edges.items():
        for neighbor in neighbors:
            nx_graph.add_edge(node, neighbor, weight=graph.distances[(node, neighbor)])

    pos = nx.spring_layout(nx_graph)
    labels = nx.get_edge_attributes(nx_graph, 'weight')
    nx.draw(nx_graph, pos, with_labels=True, node_size=700, node_color="skyblue", font_size=12)
    nx.draw_networkx_edge_labels(nx_graph, pos, edge_labels=labels)
    plt.show()


def main():
  # create a graph
    g = graph.Graph()

    g.add_node('A')
    g.add_node('B')
    g.add_node('C')
    g.add_node('D')
    g.add_node('E')
    g.add_node('F')
    g.add_node('G')
    g.add_node('H')

    g.add_edge('A', 'B', 3)
    g.add_edge('A', 'C', 2)
    g.add_edge('A', 'D', 3)
    g.add_edge('B', 'E', 7)
    g.add_edge('B', 'F', 6)
    g.add_edge('C', 'F', 3)
    g.add_edge('D', 'G', 5)
    g.add_edge('D', 'E', 6)
    g.add_edge('B', 'C', 5)
    g.add_edge('C', 'B', 1)
    g.add_edge('C', 'D', 3)
    g.add_edge('D', 'C', 4)
    g.add_edge('E', 'F', 5)
    g.add_edge('F', 'E', 1)
    g.add_edge('F', 'G', 3)
    g.add_edge('G', 'F', 4)
    g.add_edge('E', 'H', 4)
    g.add_edge('F', 'H', 8)
    g.add_edge('G', 'H', 9)

    #outputs
    visited, path = dijkstra(g, 'A')
    print(visited)
    print(path)

    display_graph(g)

# run main
if __name__ == "__main__":
    main()

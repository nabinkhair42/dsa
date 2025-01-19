G = {
    'A': ['N', 'Q'],
    'N': ['S', 'B'],
    'Q': ['M', 'C'],
    'S': ['N'],
    'B': ['N'],
    'M': ['Q'],
    'C': ['Q']
}

def DFT(G, start):
    stack = []  # Stack to keep track of nodes to visit
    visited = []  # List of visited nodes
    stack.append(start)  # Start from the given node
    
    while stack:
        popped_vertex = stack.pop()  # Pop the top node from the stack
        
        # If the node hasn't been visited, process it
        if popped_vertex not in visited:
            visited.append(popped_vertex)
            print(popped_vertex)  # Print the node
            
            # Add unvisited neighbors to the stack
            for neighbor in G[popped_vertex]:
                if neighbor not in visited:
                    stack.append(neighbor)
    
    return visited

start = 'A'
result = DFT(G, start)
print("Visited nodes in DFT order:", result)

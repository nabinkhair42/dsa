G = {
    'A': ['N', 'Q'],
    'N': ['S', 'B'],
    'Q': ['M', 'C'],
    'S': ['N'],
    'B': ['N'],
    'M': ['Q'],
    'C': ['Q']
}

def BFT(G, start):
    queue = []  # List to manage the BFS queue
    visited = []  # List to track visited nodes
    
    queue.append(start)  # Add the starting node to the queue
    
    while queue:  # While there are nodes to process
        dequeuedVertex = queue.pop(0)  # Remove the first element of the queue
        
        if dequeuedVertex not in visited:  # Process if not visited
            visited.append(dequeuedVertex)  # Mark as visited
            print(dequeuedVertex)  # Print the vertex
            
            # Enqueue all unvisited neighbors
            for neighbor in G[dequeuedVertex]:
                if neighbor not in visited and neighbor not in queue:
                    queue.append(neighbor)
    
    return visited  # Return the visited nodes in BFS order

# Start BFS from 'A'
start = 'A'
BFT(G, start)

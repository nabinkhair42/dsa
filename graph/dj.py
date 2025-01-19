import math
from queue import PriorityQueue

G = {
    'A': {'B': 3, 'C': 1},
    'B': {'C': 7, 'D': 5, 'E': 1},
    'C': {'A': 1, 'B': 7, 'D': 2},
    'D': {'B': 5, 'C': 2, 'E': 7},
    'E': {'B': 1, 'D': 7}
}

def initialize_single_source(G, source):
    cost = dict()
    prev = dict()
    for vertex in G:
        cost[vertex] = math.inf
        prev[vertex] = None
    cost[source] = 0
    return cost, prev

def relax(G, u, v, cost, prev):
    if cost[v] > cost[u] + G[u][v]:
        cost[v] = cost[u] + G[u][v]
        prev[v] = u

def dijkstra(G, source):
    cost, prev = initialize_single_source(G, source)
    visited = set()
    Q = PriorityQueue()

    # Add all vertices to the priority queue with their initial costs
    for vertex in G:
        Q.put((cost[vertex], vertex))

    while not Q.empty():
        current_cost, current_vertex = Q.get()
        if current_vertex in visited:
            continue
        visited.add(current_vertex)

        for neighbor in G[current_vertex]:
            if neighbor not in visited:
                relax(G, current_vertex, neighbor, cost, prev)
                # Update the priority queue with the new cost
                Q.put((cost[neighbor], neighbor))

    return cost, prev

# Testing the function
source = 'A'
cost, prev = dijkstra(G, source)
print("Costs from source:", cost)
print("Previous vertices:", prev)

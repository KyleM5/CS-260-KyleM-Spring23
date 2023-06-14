Final Assignment: graph
 - Create a design before you start coding the describes or shows how a graph structure could be used to store some kinds of data and attempts to solve some kind of problem.

 - Create some tests (at least two for each peice of functionality) before you start coding

 - Implement a graph class wth at least (this category effectively combines implementation and specification, partly to emphasize getting the algoriths working!):
  - A function to add a new vertex to the graph (perhaps add_vertex(vertex_name))
  - A function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination), or source.add_edge(destination))
  - A function for a shortest path algorithm (perhaps shortest_path(source, destination))
  - A function for a minimum spanning tree algorithm (example min_span_tree()).

Analyze the complexity of all of your graph behaviors (effectively part of our documentation for grading purposes)

Oce you have completed and tested the code, add to the README file what line(s) of codes or inputs and outputs show your work meeting each of the above requirements.

A graph can be used to show how things connect together. An example of a graph could be in the form of a game map, where it shows you how a location is connected to another location. Another example of a graph is show how thing link from one to another like a moore machine graph.

In order to have a fully functional graph, you would need a class to store the points (vertices) of the graph, the edges of the graph, and the potential data linked to the vertices. This could be used on a map of a town where the vertices are buildings and edges are rows. You could use it to find how a building is connected to another, and using algorithms find how to get to that location the fastest.

For functions to make this work, you would need an add vertex function to add in newly build buildings, an add edge function to represent newly built roads, and an algorithm to find the least amount of road swaps to get to your destination (the shortest path). This is not always the fastest though, because although there may be less roads to get to a destination, those roads might have a lower speed limit compared to other roads, so you would need a minimum spanning tree algorithm to get the actual fastest road.

For future developments, it would be useful to have functions to remove a vertex or edge to represent a road being shut down or a building being demolished. For this instance we will assume a newer town in which there are no bankruptcies or road damage.

To test the add vertex command, you could add the vertex and have a print to show the vertex has been added, and try and make a path to the vertex to show that other functions recognize the vertex.

To test the add edge command, you would add an edge to an existing vertex and see if it connects. If it connects, it works. Next, you could try to add a edge to a non-existent vertex and see what happens

For shortest path, you could run the code and empirically test to see if it would be the shortest (or one of the shrtest) path(s). Another way is by adding another edge that shrinks the path and see if it takes the now shorter path.

For the minimum spanning tree, you could try to run the code and see if it would be what you extected. Afterward, you could add a edge that is weighted very poorly and see if it would take it even if it shouldn't (for example, it goes to the path with the most/least weight and the new edge is very heavy or light, making the shortest path to want it but not the minimum spanning tree).
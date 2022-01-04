# Cheapest Flight Finder 
In this project, I have tried to make a flight advisor program to the 3rd party users.
To do that, This program gets the  data of airport network and data of flights,reading flight.txt and airports.txt files which contain the list of airports 
and the list of flight information from one airport to another one. Every flight information which is stored in the flight.txt file 
is two ways but written only 1 time.

Example: SAW AYT 7
it means that there are 2-way flights between these airports.The integer number which comes after the airport's IATA codes represents 
the cost of flights between these airports.

-Dijkstra's shortest path algorithm with adjacency list representation is implemented in C programing language.

FEATURES

1:List all airports in the network
2:list all the direct flights from an airport 
3:list all direct flights on the network
4:list the min-cost path from an airport to destination airport(total cost of path,every flight info in the path,cost of every flight,detailed infos of transfers)
5:list all min-cost flights from an airport to all another airports in the network
  5.1:learn the path from source to an airport on the printed list(total cost of path,every flight info in the path,cost of every flight,detailed infos of transfers).
  
  
  


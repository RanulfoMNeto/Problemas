# Meeting
Every year, the SBC (Society of Brazilians Chauffeurs) reunite all their members in a city to discuss about their profession. In these meetings they discuss about problems and suggestions for their working condition.

The biggest problem about the meeting is: the members are all scattered around the country, since their profession requires them to travel to different places everyday. For that, the choice of city where it's gonna happen the meeting is done in a way that it doesn't jeopardize any of the truckers. The criteria for this is: the longest distance to reach the local for any of the truckers is minimum as possible. In other words, the distance traveled by the farther trucker must the the shortest possible path.

Given the cities where the truckers can be found and the description of the roads that connect those cities, write a program that determines which will be the minimum distance to reach the meeting place. The truckers know the roads very well, so they always go for the shortest path. There is always a way connecting any pair of cities.

## Input
The first input line contains two integers N (2 ≤ N ≤ 100) and M (N − 1 ≤ M ≤ 10000), they represent, respectively, the amount of cities and the amount of roads that connect them. The cities are identified by integers between 0 and N - 1. The next M lines will contain, in each one, a description of the road. Each description will be composed by three integers: U, V and W, where U and V are cities (0 ≤ U ≤ N − 1 e 0 ≤ V ≤ N − 1) and W is the distance between the cities (all the roads are two-way, 1 ≤ W ≤ 100). It's always possible to travel between the cities with roads available, but it may have more than one road connecting the same pair of cities.
## Output
Your program must print a single line containing an integer, the minimum distance ran by a trucker to go to the meeting, followed all the established restrictions (in other words, this distance must be the shortest as possible).
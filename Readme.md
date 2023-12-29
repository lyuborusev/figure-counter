# Figure Counter

## Strategy

The algorithm for counting the individual figures is implemented using the Strategy Design Pattern. The reasoning for using the pattern was to have a solution that can easily change algorithms in order to validate and test different approaches.

### Matrix Traversal BFS / DFS Strategy

Currently the algorithm that is implemented and tested is based on a Traversal BSF / DFS approach. The input matrix is iterated over it's rows and cols. When the algorithm reaches a marked element a traversal is being made in order to set the figure as 'visited'. Elements that are already makred as 'visited' are skipped by.

### Single-pass Scan / Heuristic approach

An attempt was made to implement a solution that was not based on BFS / DFS traversal utilizing a greedy algorithm. The idea of the algorithm is to iterate through the elements and to mark each cell based on the following logic:
1) If the element to the left and the element to the top of the current cell are not marked, then we create a new 'label' and mark our current cell. The heuristic assumes that we begin to explore a new figure in the matrix.
2) If either the element on the left or to the top are marked, then we use the label to mark the current cell. This assumes that we are extending an already detected figure.
3) In case we have different labels in the element to the left and one to the top, then we assume that two labels were generated for the same figure, thus reducing the count of the detected figures.

The algorithm above so far is not considered to be working as testing it against the Matrxi Traversal Strategy proves that in certain test cases the results from both approaches are different.

## Utils

Several classes are classified as 'utilities', including a generic matrix, repository for marking visited elements, and BFS / DFS strategies for traversing the matrix.

## Tests

Testing is crucial for implementing algorithmic solutions like the task in hand. First and foremost we are using whatever is given as examples with the task description.

### Random test generation

On top of hand-crafted test cases we are utilizing randomly generated matrices. This way we can test the solution on a variety of input formats, and also can easily create performance tests using large input data. The random test cases can be used to validate different algorithms against each other. In case of inconsistent results we are investigating both solutions to figure out where the problem is.

## Project structure / Documentation

### IStrategy

Base interface for implementing the Strategy Design Pattern. Used mostly to define the virtual destructor.

### FigureCountStrategy

Extension of the base strategy defining the method interface for invoking the algorithm.

### Context

Straight-forward implementation of user-code/context following the Strategy Design Pattern

### StrategyTraverse

Implements a grid traversal approach utilizing either BFS or DFS.

### StrategyScan

An attempt to implement a different solution not based on traversal with BFS / DFS

### TraverseStrategy

A sub-IStrategy interface implementing functionality for doing either BFS or DFS. The nunace of the traversal is achieved by the underlying data structure provided by ElementQueue.

### ElementQueue

Handles the 'queue' of pending elements that need to be visited by the generic grid-traversal algorithm implemented in StrategyTraverse

### Matrix

A utility class encapsulating the underlying matrix grid. Provides flexibility to change the input data type.

### VisitedRepo

Stores the matrix elements that are visited by the figure counter algorithms so that the input matrix is not modified by our solutions.
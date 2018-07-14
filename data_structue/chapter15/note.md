# Memory Management
With Python,all objects are stored in a pool of memory,known as **memory heap or Python heap**
1. Garbage Collection
- Reference Counts
This is the count of how many references to the object known as **reference count**
2. Cycle Detection
There may exist a group of objects that have references to each other,even though none of those objects are reachable from a root object(Mark-Sweep Algorithm)
3. Additional Memory Used by the Python Interpreter
- The run-time call stack
4. Memory hierarchies and caching
- memory systems
- caching  strategies
    - caching and blocking
        - temporal locality 
        - spatial locality 
    - caching in web browsers
    - page replacement algorithms
5. External searching and B-Trees
6. External-Memory Sorting 
- Multi-way Merge-Sort 
- Multi-way Merging 


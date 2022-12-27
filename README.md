# Most common algorithms implementation

## Content

* Compression
    * Huffman
    * Lzw
* Crypto
    * MD5
    * SHA1
    * UUID
* Geometry
    * GrahamScan
    * IntervalSearchTree
    * KdTree
    * LineCrossFinder
    * RectCrossFinder
* Graph
    * AcyclicShortestPaths 
    * BellmanFordShortestPaths
    * BreadthFirstRoutes
    * DepthFirstRoutes
    * ComponentSpreader
    * DepthFirstOrder
    * DijkstraShortestPaths
    * DirectedCycleFinder
    * FlowNetwork
    * FordFulkerson
    * KruskalMinSpanningTree
    * MultiSourceShortestPaths
    * PrimsMinSpanningTree
    * StrongComponentSpreader
    * TopologicalOrderIterator
* Hash
    * LinearProbingHashTree
    * ChainingHashTree
* Sort
    * BottomUpMergeSort
    * HeapSort
    * InsertionSort
    * MergeSort
    * QuickSort
    * SelectionSort
    * ShellSort
    * ThreeWayQuickSort
    * Select
* String
    * LsdRadixSort
    * MsdRadixSort
    * BoyerMooreSubstringSearch
    * KnuthMorrisPrattSubstringSearch
    * LongestCommonPrefix
    * RabinKarpSubstringSearch
    * RegExpMatcher
    * TernarySearchTries
    * ThreeWayRadixSort
* Tree
    * BinaryTree
    * RedBlackTree
    * BreadthOrderTraverse (with/without recursion)
    * DepthPreOrderTraverse (with/without recursion)
    * DepthInOrderTraverse (with/without recursion)
    * DepthPostOrderTraverse (with/without recursion)
* UnionFind
    * QuickFind
    * QuickUnion
    * UnionFind

## ToDo

* Least Recently Used Cache
* Most Recently Used Cache
* Circular Buffer
* Probabilistic Data Structures
  * Bloom filter
  * Cuckoo filter
* HyperLogLog

## How-To

### Build

```bash
$ cmake -S . -B build
$ cmake --build build --parallel
```

# Contact

# License

The license is the MIT license.

## Materials

+ ["Algorithms" by Robert Sedgewick and Kevin Wayne](https://algs4.cs.princeton.edu).

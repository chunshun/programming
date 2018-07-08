1. Python's Sequence Types
'sequence` classes:**lsit**,**tuple**,and **str** classes
- referential structures
The fact that lists and tuples are referential structures is significant to the semantics of these classes.For an example,when you compute a slice of a list, the result is a new list instance,but that new list has references to the same elements that are in the original list.
- compact arrays
The overall memory usage will be much lower for a compact structure because there is no overhead devoted to the explicit storage of the sequence of memory references(in addition to the primary data).That is,a referential structure will typically use 64-bits for the memory address stores in the array, on top of whatever number of bits are used to represent the object that is considered the element.Also, each Unicode character stored in a compact array within a string typically requires 2 bytes.If each character were stored independently as a one-character string,there would be significantly more bytes used.

Another important advantage to a compact structure for high-performance computing is that the primary data are stored consecutively in memory.Note well that this is not the case for a referential structure.That is,even though a list maintains careful ordering of the sequence of memory addresses,where those elements reside in memory is not determined by the list.

Primary support for compact arrays is in a module named `array`.That module define a class,also named `array`,providing compact storage for arrays of primitive data types.

```python 
sys.getsizeof(array.array('i',list(range(10))))
104

sys.getsizeof(list(range(10)))
200
```
The `array` module does not provide support for making compact arrays of user-dependent data types.Compact arrays of such structurres can be created with the lower-level support of a module names `ctypes`
- dynamic array
To add elements to the list,with no apparent limit on the overall capacity of the list.To provide this abstraction,Python relies on an algorithmic sleight of hand known as **dynamix array**

The first key to providing the semantics of a dynamic array is that a list instance maintains an underlying array that often has greater capacity than the current length of the list.The extra capacity makes it easy to append a new element to the list by using the next available cell of the array.


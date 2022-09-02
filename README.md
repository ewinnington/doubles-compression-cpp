# doubles-compression-cpp
Implementing in memory compression of doubles, based on XOR compression


Implementing the Xor Compression for double data as described in the Facebook Gorilla paper (4.1.2 Compressing values) 

- https://www.vldb.org/pvldb/vol8/p1816-teller.pdf

Illustrated here 

- https://www.timescale.com/blog/time-series-compression-algorithms-explained/

Regarding the implementation, I had one change from the paper 

```cpp
#define BITS_LEADING_LENGTH 6 //Contrary to the paper claims, I need 6 bits to encode the leading zeros and not 5 bits
#define BITS_XOR_LENGTH 6
``` 

Also very interesting for a follow-up paper to implement https://github.com/andybbruno/TSXor

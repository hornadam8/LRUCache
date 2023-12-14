# LRU Cache implementation

## Running the demo
Simply cd into the project root, run `make` then `./lru`

## FAQ
### What is an LRU cache?
An LRU cache is a data structure for persisting a limited amount of data that may be expensive (in latency or actual money)
to compute otherwise. Most implementations (this one included) use a map to store cached info quickly, but implementations 
vary in terms of how the keep track of priority/recency. This implementation uses a doubly linked list, where the recency
of access decreases from head to tail and the tail node is removed when the capacity is exceeded.

### Why would anyone ever need this?
Some real world examples might be an expensive database query, an API call that costs money (and time) or a math function
that is expensive (long-running) to compute. So if, for example, I'm building a service that sends push notifications for 
your instagram account, I may need to retrieve some information about you and/or your phone in order to deliver that 
notification. In almost all cases, that means I need to query a database for your information. That can be an expensive 
process both in terms of latency and actual money. If the database is cloud-hosted, reads typically count toward your 
bill and in all cases, it takes longer to reach out to a database over the internet than it does to access data that is 
already in-memory. So if you post a picture and someone likes it, my service may need to reach out to the database to get 
the information to send you a notification. If I use an LRU Cache over that database, when a second person likes your 
picture I can retrieve your information from the cache instead and significantly reduce cost and latency.

## Structures used

### Doubly-Linked List
My doubly-linked list implementation is fairly simple, it consists of nodes that hold a key (the same as the hashmap key)
and pointers to the next and previous nodes. The list itself also has a size so that it can be checked against the LRU 
cache's capacity. I used a template to allow for multiple key types, at present it only supports strings and ints, but 
other types can be easily added at the bottom of the .cpp file

### Map
This is a C++ standard library data structure that stores keys associated with values.

### LRU Cache
The LRU cache has a capacity that governs the number of items it can hold, a doubly-linked list to maintain priority and 
a map for accessing values. This class uses a template so that many types of functions can be cached. The current list of
supported type combinations is below, but others can easily be added at the bottom of its .cpp file.
LruCache<int, long>;
LruCache<int, int>;
LruCache<int, bool>;
LruCache<int, map<int, int> >;
LruCache<int, map<int, bool> >;
LruCache<string, string>;
LruCache<string, map<string, string> >;
LruCache<string, map<char, int> >;
LruCache<string, vector<string> >;
LruCache<int, vector<int> >;
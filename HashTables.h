//Created: Rafe Cooley 11/13/2017
// HashTable Class header
// - this class will keep track of two different hash tables each using a different type of collision avoidance method
// includes Dr. Tom Bailey's LinkedList & Node implementations
// - modified Node for typeof(entry_)==string

#include <unordered_map>
#include <string>

#include "LinkedList.h"//change to .h

typedef unsigned int unint;

//this bucket is used by the open addressing table
struct openBucket{
  bool collision;//whether or not there was a collision at this field
  string entry_;
};

//this bucket is used by the seperate chaining table
struct chainBucket{
  bool collision;//whether or not there was a collision at this field
  List *bucketList;
};

class HashTables{
private:
  std::unordered_map<unint,openBucket> openAddressTable;
  std::unordered_map<unint,chainBucket> chainingTable;

public:
  unint openCollisions;//track number of collisions in open addressing
  unint chainedCollisions;//track number of collisions in separate chaining

  void addToTables(unint inputHash, std::string text);
  void addToOpenAddress(unint inputHash, std::string text);
  void addToChaining(unint inputHash, std::string text);
  void CollisionReport();
  void PrintOpenTable();
  void PrintChainTable();
  void PrintTables();
};

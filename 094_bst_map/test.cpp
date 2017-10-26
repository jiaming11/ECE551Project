#include <iostream>
#include <cstdlib>
#include "bstmap.h"
#include "map.h"
#include <string>

using namespace std;

int main(){
  BstMap<int,int> map;
  map.add(2,2);		   
  map.add(4,4);
  map.add(1,1);
  map.add(7,7);
  map.add(3,3);
  map.add(9,9);
  map.add(-1,-1);
  map.add(88,88);
  map.add(17,17);
  map.add(-23,-23);
  map.add(16,16);
  map.add(44,44);
  map.add(77,77);
  map.remove(2);
  map.remove(16);
  map.remove(-1);
  /*  try{
    map.lookup(0);
  }
  catch(std::invalid_argument &ia){
    cerr<<ia.what();
    exit(0);
    }*/
  map.print();
  return EXIT_SUCCESS;
}
#include <iostream>
using namespace std;

int main (){



}

class LRUCache {

    queue<pair<int , int >>cache ;
    int cap ;

  public:

    LRUCache(int cap) {
        this->cap = cap ;
    }

    int get(int key) {
    queue<pair<int , int >>tempCache ;
        int ans  = -1 ; 
    while(!cache.empty()){
       if(cache.front().first !=key) tempCache.push(cache.front()); 
       else ans=cache.front().second ;
       cache.pop();
    }
    if(ans != -1) cache.push({key , ans});
    while(!tempCache.empty()){
       cache.push(tempCache.front()); 
       tempCache.pop();
    }
    return ans ;
    }

        
    void put(int key, int value) {
    queue<pair<int , int >>tempCache ;
        int ans  = -1 ; 
    while(!cache.empty()){
       if(cache.front().first !=key) tempCache.push(cache.front()); 
       cache.pop();
    }
    cache.push({key , value});
    int i = cap-1;
    while(!tempCache.empty() && i>0){
       cache.push(tempCache.front()); 
       tempCache.pop(); i--;
    }
    }
};
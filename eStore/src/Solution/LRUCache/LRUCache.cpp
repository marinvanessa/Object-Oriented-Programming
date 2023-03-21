#include "LRUCache.h"
#include <algorithm>
#include<list>
#include<unordered_map>
using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	list<int> myList; 
	unordered_map<int, list<int>::iterator> myMap; 
	unsigned int myCapacity = capacity; 
	for (auto it = requestsNo.begin(); it != requestsNo.end(); ++it){
		if (myMap.find(*it) == myMap.end()){
			if (myList.size() == myCapacity){
				int last = myList.back();
				myList.pop_back();
				myMap.erase(last);
			}
		} else{
			myList.erase(myMap[*it]);
		}
		myList.push_front(*it);
		myMap[*it] = myList.begin();
	}
	vector<int> lru(myList.begin(), myList.end());
	return lru;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	this->lru = aux;
}

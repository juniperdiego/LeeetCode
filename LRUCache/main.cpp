#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

struct cacheNode{
   int  key; 
   int  val;
   cacheNode(int k, int v)
   {
        key = k;
        val = v;
   }
};


class LRUCache{
    private:
        int m_capacity;
        list<cacheNode> m_list;//double link of cacheNode
        map< int, list<cacheNode>::iterator > m_map; // map of key and list::iterator

    public:
        LRUCache(int capacity)
        {
            m_capacity = capacity;
        }

        int get(int key) {
            if(m_map.find(key) == m_map.end())
            {
                return -1;
            }
            else
            {
                //move the node to head of double list
                list<cacheNode>::iterator it = m_map[key];
                m_list.splice(m_list.begin(), m_list, it);
                return m_list.begin()->val;
            }
        }

        void set(int key, int value)
        {
            if(m_map.find(key) == m_map.end())
            {
                //delete the back one if reach capacity
                if(m_capacity == m_list.size())
                {
                    cacheNode tmp = m_list.back();    
                    m_list.pop_back();
                    m_map.erase(tmp.key);
                }
                // insert new one into the head
                cacheNode node(key, value); 
                m_list.push_front(node);
                m_map[key]= m_list.begin();
            }
            else
            {
                //move the node to head of double list
                list<cacheNode>::iterator it = m_map[key];
                m_list.splice(m_list.begin(), m_list, it);
                //update value
                m_list.begin()->val = value;
                
            }

        }

        void printCache()
        {
            for(list<cacheNode>::iterator it = m_list.begin(); it != m_list.end(); it++)
            {
                cout << "key:\t" << it->key <<"\tvalue\t" << it->val <<endl;
            }
            cout << endl;
        }
};


int main()
{
    LRUCache cache(5);
    cache.set(1, 1);
    cache.set(2, 2);
    cache.set(3, 4);
    cache.set(4, 4);
    cache.set(5, 5);
    cache.printCache();
    cache.set(6, 6);
    cache.printCache();
    cache.set(2, 9);
    cache.printCache();
    cache.set(3, 3);
    cache.printCache();
    cache.get(5);
    cache.printCache();
    return 0;
}

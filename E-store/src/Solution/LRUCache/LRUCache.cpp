#include "LRUCache.h"
#include<algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity=capacity;
    lru = vector<int>(capacity);
	size=0;
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
    int i, j, k;
    for(i=0; i<requestsNo.size(); i++)
    {
        int flag=0;
        for(j=0; j<size; j++)
        {
            if(lru[j]==requestsNo[i])
            {
                for (k = j - 1; k >= 0; k--)
                    lru[k + 1] = lru[k];
                lru[0]=requestsNo[i];
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(size==capacity)
            {
                for(j=size-2; j>=0; j--)
                    lru[j+1] = lru[j];
            }
            else
            {
                size++;
                for(j=size-2; j>=0; j--)
                    lru[j+1] = lru[j];
            }
            lru[0] = requestsNo[i];
        }
    }
    return lru;
    //aici vreau sa ma folosesc de vectorul deja existent si sa adaug in cel lru si fac asta prin urmatoarele reguli
    //in primul ranf parcurg vetorii
    //verific daca este spatiul de 4 in cel in care bag
    //verific daca exista deja nr
    //daca nu exista il adaug
    //daca exista vad unde este il iau din pozitia aia , mut elementele si dupa il pun in fata si tot asa
    //daca vectorul e plin si nu se repeta un element  streg ultimul element
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
	this->capacity=capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
        for(unsigned int i=0;i<lru.size();i++)
        {
            lru[i]=aux[i];
        }

}
//in rest am getteri setteri si contructori

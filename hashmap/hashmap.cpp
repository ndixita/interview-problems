#include <iostream>
using namespace std;

const size_t hashMapSize = 1000;

template<class K, class V>
class HashNode {
public:
	K key;
	V val;
	HashNode(K key, V val) {
		this->key = key;
		this->val = val;
	}
};

template<class K, class V>
class HashMap {
	size_t size;
	size_t capacity;
	HashNode<K, V>* dummy;
	HashNode<K, V>** arr;

public:
	HashMap() {
		capacity = hashMapSize;
		size = 0;
		dummy = new HashNode<K, V>(-1, -1);
		arr = new HashNode<K, V>*[capacity];
		for(int i = 0; i < capacity; i++) {
			arr[i] = NULL;
		}
	}

	size_t sizeOf() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	int hashCode(K key) {
		return key % capacity;
	}

	void put(K key, V val) {
		int bucket = hashCode(key);
		HashNode<K, V> *temp = new HashNode<K, V>(key, val);
		while(arr[bucket] != NULL && arr[bucket]-> key != key && arr[bucket]->key != -1) {
			bucket++;
			bucket %= capacity;
		}

		if(arr[bucket] == NULL || arr[bucket]->key == -1) size++;
		arr[bucket] = temp;
	}

	V get(K key) {
		int bucket = hashCode(key);
		int counter  = 0;
		while(arr[bucket] != NULL) {
			if(counter++ > capacity) return V(NULL);
			if(arr[bucket]->key == key) return arr[bucket]->val;
			bucket++;
			bucket %= capacity;
		}
		return V(NULL);
	}

	V deleteKey(K key) {
		int bucket = hashCode(key);
		while(arr[bucket] != NULL) {
			if(arr[bucket]->key == key) {
				size--;
				HashNode<K, V> *temp = arr[bucket];
				arr[bucket] = dummy;
				return temp->val;
			}
			bucket++;
			bucket %= capacity;
		}

		return V(NULL);
	}

	void display() {
		for(int i = 0; i < capacity; i++) {
			if(arr[i] != NULL && arr[i]->key != -1) {
				cout << "key is: " << arr[i]->key << " and the value is: " << arr[i]->val << endl;
			}
		}
	}

};

int main() {
	HashMap<int, int> *hmap = new HashMap<int, int>();
	hmap->put(4, 5);
	cout << (hmap->get(1)) << endl;
	cout << (hmap->deleteKey(1)) << endl;
	hmap->put(2, 3);
	hmap->display();
	return 0;
}
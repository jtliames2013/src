#define DEFAULT_SIZE 16

template<typename K, typename V>
class HashNode {
public:
    HashNode(K& k, V& v):key(k), value(v) {}
    K key;
    V value;
};

template<typename K>
struct KeyHash {
    int operator()(K& k) {
        return reinterpret_cast<int>(k) % DEFAULT_SIZE;
    }
};

template<typename K, typename V, typename F=KeyHash<K>>
class HashMap {
public:
    HashMap() {
        data.resize(DEFAULT_SIZE);
        size=0;
    }

/*
    // separate chaining
    void put(K key, V value) {
        int h=hashFunc(key);
        for (auto it=data[h].begin(); it!=data[h].end(); ++it) {
            if (it->key==key) {
                it->value=value;
                return;
            }
        }
        data[h].push_back(HashNode<K, V>(key, value));
    }

    V get(K key) {
        int h=hashFunc(key);
        if (data[h].empty()) return 0;
        for (auto it=data[h].begin(); it!=data[h].end(); ++it) {
            if (it->key==key) return it->value;
        }
        return NULL;
    }

    void del(K key) {
        int h=hashFunc(key);
        if (data[h].empty()) return;
        for (auto it=data[h].begin(); it!=data[h].end(); ++it) {
            if (it->key==key) {
                data[h].erase(it);
                return;
            }
        }
    }
*/

    // open addressing
    void put(K key, V value) {
        int h=hashFunc(key), i=h;
        do {
            if (data[i]==NULL) break;
            if (data[i]->key==key) {
                data[i]->value=value;
                return;
            }
            i=(i+1)%DEFAULT_SIZE;
        } while (i!=h);

        if (size==DEFAULT_SIZE) return;
        data[i]=new HashNode<K, V>(key, value);
        size++;
    }

    V get(K key) {
        int h=hashFunc(key), i=h;
        do {
            if (data[i]==NULL) return NULL;
            if (data[i]->key==key) return data[i]->value;
            i=(i+1)%DEFAULT_SIZE;
        } while (i!=h);

        return NULL;
    }

    void del(K key) {
        int h=hashFunc(key), i=h;
        do {
            if (data[i]==NULL) return;
            if (data[i]->key==key) {
                delete data[i];
                data[i]=NULL;
                size--;
                return;
            }
            i=(i+1)%DEFAULT_SIZE;
        } while (i!=h);
    }
private:
    // vector<list<HashNode<int, int>>> data;
    vector<HashNode<K, V>*> data;
    int size;
    F hashFunc;
};

int main(int argc, char** argv) {
    HashMap<int, int> mp;
    for (int i=0; i<10; ++i) mp.put(i, i);
    for (int i=0; i<10; ++i) cout << mp.get(i) << endl;
    for (int i=0; i<10; i+=2) mp.del(i);
    for (int i=0; i<10; ++i) cout << mp.get(i) << endl;
    return 0;    
}


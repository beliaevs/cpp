// хотим реализовать RandomizedSet
// добавлять значение
// удалять значение
// выдавать случайное значение
#include<unordered_map>
#include<vector>
#include<random>

template<typename V>
class RandomizedSet {
    std::unordered_map<V, int> mp_ {};
    std::vector<V> data_{};
    //std::mt19937 rnd{};
    mutable std::mt19937 rnd{};
public:
    RandomizedSet() {}

    bool insert(V val) {
        if(mp_.contains(val)) {
            return false;
        }
        mp_[val] = data_.size();
        data_.push_back(val);
        return true;
    }

    bool remove(V val){
        if(not mp_.contains(val)){
            return false;
        }
        int ind = mp_[val];
        if(ind + 1 != data_.size()) {
            std::swap(data_[ind], data_.back());
            mp_.erase(val);
        }
        data_.pop_back();
        mp_.erase(val);
        return true;
    }

    V getRandom() const {
        return data_[rnd() % data_.size()];
    }
};

// added
int main()
{
    RandomizedSet<int> s;
    s.insert(2);
    s.getRandom();
    s.remove(1);
    return 0;
}
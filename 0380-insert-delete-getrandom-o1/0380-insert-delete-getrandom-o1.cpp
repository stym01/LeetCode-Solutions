class RandomizedSet {
public:
    set<int>st;
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        if(st.count(val)==0){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.count(val)==0) return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int x=rand() %st.size();
        cout<<x<<endl;
        return *(next(st.begin(),x));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
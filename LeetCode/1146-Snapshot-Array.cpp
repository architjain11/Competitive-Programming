class SnapshotArray {
public:
    map<int, map<int, int>> snaps;
    int snapID=0;

    SnapshotArray(int length) {
        map<int, int> m;
        m[0]=0;
        for(int i=0; i<length; ++i)
            snaps[i]=m;
    }
    
    void set(int index, int val) {
        snaps[index][snapID]=val;
    }
    
    int snap() {
        return snapID++;
    }
    
    int get(int index, int snap_id) {
        auto it=snaps[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
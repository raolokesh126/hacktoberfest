/**
 * Implement a SnapshotArray class that supports the following interface:

SnapshotArray(int length): initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val): sets the element at the given index to be equal to val.
int snap(): takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id): returns the value at the given index, at the time we took the snapshot with the given snap_id
Problem Statement Link: https://leetcode.com/problems/snapshot-array/
*/
class SnapshotArray {
public:
  unordered_map<int, map<int, int>> mp;
  int cur_snap = 0;
  SnapshotArray(int length) {}
  int snap() { return cur_snap++; }
  void set(int index, int val) {
    mp[index][cur_snap] = val;
  }
  int get(int index, int snap_id) {
    auto it = mp[index].upper_bound(snap_id);
    return it == begin(a[index]) ? 0 : prev(it)->second;
  }
};
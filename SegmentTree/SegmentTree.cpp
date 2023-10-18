#include<iostream>
#include<vector>

using namespace std;

class SegmentTree{

    public:
        vector<int> segmentTree;
        SegmentTree(int n){
            segmentTree.resize(4*n);
        }

        int left(int idx){
            return 2*idx;
        }

        int right(int idx){
            return 2*idx + 1;
        }

        void createSegmentTree(int idx, int start, int end, vector<int>& arr){
            if(start == end){
                segmentTree[idx] = arr[start];
                return;
            }

            int mid = (start + end)/2;
            int leftIdx = left(idx);
            int rightIdx = right(idx);

            createSegmentTree(leftIdx, start, mid, arr);
            createSegmentTree(rightIdx, mid+1, end, arr);

            segmentTree[idx] = min(segmentTree[leftIdx], segmentTree[rightIdx]);
        }

        int query(int st_idx, int st_start, int st_end, int query_start, int query_end){
            
            // current segment is outside
            if(st_start > query_end || st_end < query_start){
                return 1e9;
            }

            // query range fully covers the node 
            if(query_start <= st_start && query_end >= st_end){
                return segmentTree[st_idx];
            }

            int mid = (st_start + st_end)/2;
            int leftResult = query(left(st_idx), st_start, mid, query_start, query_end);
            int rightResult = query(right(st_idx), mid+1, st_end, query_start, query_end);

            return min(leftResult, rightResult);
        }

        int query(int start, int end, vector<int>& arr){
            return query(1, 0, arr.size()-1, start, end);
        }

        int update(int st_idx, int st_start, int st_end, int update_idx, int val){

            if(st_start > update_idx || st_end < update_idx){
                return segmentTree[st_idx];
            }

            if(st_start == st_end){
                return segmentTree[st_idx] = val;
            }

            int mid = (st_start + st_end)/2;
            int leftResult = update(left(st_idx), st_start, mid, update_idx, val);
            int rightResult = update(right(st_idx), mid+1, st_end, update_idx, val);
            return segmentTree[st_idx] = min(leftResult, rightResult);
             
        }

        void update(int idx, int val, vector<int>& arr){
            arr[idx] = val;
            update(1, 0, arr.size()-1, idx, val);
        }

};


int main(){
//                     0 1 2 3 4 5  6 7  8  9 0 1 2 3 4  5  6
    vector<int> arr = {9,3,5,1,6,13,7,11,14,9,6,5,4,3,12,15,12};
    int n = arr.size();


    SegmentTree* st = new SegmentTree(n);
    st->createSegmentTree(1,0,n-1,arr);
    cout << st->query(0,2,arr) << "\n";
    cout << st->query(0,7,arr) << "\n";
    cout << st->query(4,12,arr) << "\n";
    cout << st->query(5,11,arr) << "\n";
    st->update(11,6,arr);
    cout << st->query(5,11,arr) << "\n";

}
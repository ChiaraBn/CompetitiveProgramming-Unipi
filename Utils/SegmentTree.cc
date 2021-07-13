#include <bits/stdc++.h>

#define LEFT(i)  (2*i+1)
#define RIGHT(i) (2*i+2)

using namespace std;

struct SegmentTree {
    vector<int64_t> st, lazy;
    int n;

    SegmentTree(int size){
        n = size;
        int s = (int)ceil(log2(size));
        int tree_size = 2*(int)pow(2, s) - 1;
        st.resize(tree_size, 0);
        lazy.resize(tree_size, 0);
    }

    int64_t sum(int l, int r) {
        return sum_to(0, 0, n-1, l, r);
    }

    void update(int l, int r, int64_t val) {
        update_to(0, 0, n-1, l, r, val);
    }

    void push(int curr, int start, int end) {
        if (lazy[curr] != 0) {
            st[curr] += lazy[curr];

            if (start != end) {
                lazy[LEFT(curr)] += lazy[curr];
                lazy[RIGHT(curr)] += lazy[curr];
            }
            lazy[curr] = 0;
        }
    }

    int64_t sum_to(int curr, int start, int end, int ql, int qr) {
        push(curr, start, end);

        if (start >= ql && end <= qr) {
            return st[curr];
        }
        else if (start > qr || start > end || end < ql) {
            return 0;
        }

        int mid = (start + end)/2;
        return sum_to(LEFT(curr), start, mid, ql, qr) +
               sum_to(RIGHT(curr), mid+1, end, ql, qr);
    }

    void update_to(int curr, int start, int end, int ql, int qr, int64_t val) {
        push(curr, start, end);

        if (start > qr || end < ql)
            return;

        if (start >= ql && end <= qr) {
            st[curr] += val;
            
            if (start != end) {
                lazy[LEFT(curr)] += val;
                lazy[RIGHT(curr)] += val;
            }
        }
        else {
            int mid = (start + end)/2;
            update_to(LEFT(curr), start, mid, ql, qr, val);
            update_to(RIGHT(curr), mid+1, end, ql, qr, val);
            st[curr] += val;
        }
    }
};
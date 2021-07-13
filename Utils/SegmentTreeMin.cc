#include <bits/stdc++.h>

#define LEFT(i)  (2*i+1)
#define RIGHT(i) (2*i+2)

using namespace std;

struct SegmentTreeMin  {
    vector<int64_t> st, lazy;
    int n;

    SegmentTreeMin (const vector<int64_t> &a) {
        n = a.size();
        int x = (int)ceil(log2(n));
        int tree_size = 2*(int)pow(2, x) - 1;
        st.resize(tree_size, 0);
        lazy.resize(tree_size, 0);
        build(a, 0, 0, n-1);
    }

    void build(const vector<int64_t> &a, int curr, int start, int end) {
        if (start > end) 
            return;

        if (start == end)  {
            st[curr] = a[start];
            return;
        }

        int mid = (end + start)/2;
        build(a, LEFT(curr), start, mid);
        build(a, RIGHT(curr), mid+1, end);
        st[curr] = min(st[LEFT(curr)], st[RIGHT(curr)]);
        return;
    }

    int64_t rmq(int l, int r) {
        if (l > r) 
            return (min(rmq(0, r), rmq(l, n-1)));
        else 
            return (min_to(0, 0, n-1, l, r));
    }

    void update(int start, int end, int64_t val) {
        if (start > end) {
            update_to(0, 0, n-1, start, n-1, val);
            update_to(0, 0, n-1, 0, end, val);
        }
        else {
            update_to(0, 0, n-1, start, end, val);
        }
    }

    void push (int curr, int start, int end) {
        if (lazy[curr] != 0) {
            st[curr] += lazy[curr];

            if (start != end) {
                lazy[LEFT(curr)] += lazy[curr];
                lazy[RIGHT(curr)] += lazy[curr];
            }
            lazy[curr] = 0;
        }
    }

    int64_t min_to(int curr, int start, int end, int ql, int qr) {
        push (curr, start, end);

        if (start >= ql && end <= qr) {
            return st[curr];
        }
        else if (start > qr || start > end || end < ql) {
            return INT_MAX;
        }

        int mid = (start + end)/2;
        return min(min_to(LEFT(curr), start, mid, ql, qr), 
                   min_to(RIGHT(curr), mid+1, end, ql, qr));
    }

    void update_to(int curr, int start, int end, int ql, int qr, int64_t val) {
        push (curr, start, end);

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
            st[curr] = min(st[LEFT(curr)], st[RIGHT(curr)]);
        }
    }
};
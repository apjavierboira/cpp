// segtree
struct SegTree {
    int n; 
    vector<long long> st, lazy;

    SegTree(int n): n(n) {
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }   

    void build(int node, int l, int r, const vector<long long>& a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node*2, l, mid, a);
        build(node*2+1, mid+1, r, a);
        st[node] = st[node*2] + st[node*2+1];
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            st[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid+1, r, ql, qr, val);
        st[node] = st[node*2] + st[node*2+1];
    }

    long long query(int node, int l, int r, int idx) {
        push(node, l, r);
        if (l == r) return st[node];
        int mid = (l + r) / 2;
        if (idx <= mid) return query(node*2, l, mid, idx);
        return query(node*2+1, mid+1, r, idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    SegTree st(n);
    st.build(1, 1, n, a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            st.update(1, 1, n, l, r, x);
        } else {
            int k;
            cin >> k;
            cout << st.query(1, 1, n, k) << "\n";
        }
    }
    return 0;
}
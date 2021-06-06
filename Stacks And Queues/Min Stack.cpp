vector<int> mi, v;
MinStack::MinStack() {
    v.clear();
    mi.clear();
    //I don't like it. what about parallel?? but we are blind here.
}

void MinStack::push(int x) {
    if(v.size() == 0) mi.push_back(0);
    else if(x < v[mi[mi.size() - 1]]) mi.push_back(v.size());
    v.push_back(x);
}

void MinStack::pop() {
    if(v.size() != 0) {
        v.pop_back();
        if(mi[mi.size() - 1] == v.size()) mi.pop_back();
    }
}

int MinStack::top() {
    if(v.size() == 0) return -1;
    return v[v.size() - 1];
}

int MinStack::getMin() {
    if(mi.size() == 0) return -1;
    else return v[mi[mi.size() - 1]];
}

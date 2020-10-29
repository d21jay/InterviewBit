bool cc(vector<int> &a, vector<int> &b) {
    //departure before arrival for same day.
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0]; 
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<vector<int>> book;
    for(int i = 0; i < arrive.size(); i++) {
        book.push_back({arrive[i], 1});
        book.push_back({depart[i], -1});
    }
    sort(book.begin(), book.end(), cc);
    int booked = 0;
    for(int i = 0; i < book.size(); i++) {
        booked += book[i][1];
        if(booked > K) return false;
    }
    return true;
}
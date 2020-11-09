//catastrophic. need to store 2 set of values for each substring in a sub-problem.
//hard to maintain through (few) tables.
//lets go for an unordered_map 
unordered_map<string, bool> memory;

void engine(string A, string B) {
    if(A.size() == 1) {
        memory[A + " " + B] = (A == B);
        return;
    }
    if(A == B){
        memory[A + " " + B] = true;
        return;
    }
    string s1;
    string s2;
    string s3;
    string s4;
    bool lflag;
    bool rflag;
    for(int i = 1; i < A.size(); i++) {
        s1 = A.substr(0, i);
        s2 = A.substr(i, A.size() - i);
        
        s3 = B.substr(0, i);
        if(memory.find(s1 + " " + s3) == memory.end()) engine(s1, s3);
        lflag = memory.find(s1 + " " + s3) -> second;
        
        s4 = B.substr(i, A.size() - i);
        if(memory.find(s2 + " " + s4) == memory.end()) engine(s2, s4);
        rflag = memory.find(s2 + " " + s4) -> second;
        if(lflag && rflag){
            memory[A + " " + B] = true;
            return;
        }
        s3 = B.substr(A.size() - i, i);
        if(memory.find(s1 + " " + s3) == memory.end()) engine(s1, s3);
        lflag = memory.find(s1 + " " + s3) -> second;
        
        s4 = B.substr(0, A.size() - i);
        if(memory.find(s2 + " " + s4) == memory.end()) engine(s2, s4);
        rflag = memory.find(s2 + " " + s4) -> second;
        if(lflag && rflag){
            memory[A + " " + B] = true;
            return;
        }
    }
    memory[A + " " + B] = false;
    return;
}

int Solution::isScramble(const string A, const string B) {
    if(A.size() != B.size()) return 0;
    if(A == B) return 1;
    memory.clear();
    string s1 = A;
    string s2 = B;
    engine(s1, s2);
    if(memory[s1 + " " + s2]) return 1;
    return 0;
}
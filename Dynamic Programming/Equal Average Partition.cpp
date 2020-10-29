vector<vector<vector<bool>>> solBook;
vector<vector<vector<bool>>> calculated;
bool isPossible(int size, long long int val, int ind, vector<int> &A) {
    if(size == 0) return false;
    bool poss;
    if(ind == 0) {
        calculated[size][val][ind] = true;
        return solBook[size][val][ind];
    }
    bool pos1, pos2 = false;
    if(calculated[size][val][ind-1]){
        pos1 = solBook[size][val][ind-1];
    }
    else pos1 = isPossible(size, val, ind-1, A);
    if(A[ind] <= val) {
        if(calculated[size - 1][val - A[ind]][ind-1]){
            pos2 = solBook[size - 1][val - A[ind]][ind-1];
        }
        else pos2 = isPossible(size - 1, val - A[ind], ind-1, A);
    }
    poss = (pos1 || pos2);
    solBook[size][val][ind] = poss;
    calculated[size][val][ind] = true;
    return poss;
}
//non-negative numbers :-)
vector<vector<int> > Solution::avgset(vector<int> &A) {
    vector<vector<int>> ans;
    if(A.size() < 2) return ans;
    long long int tar = 0;
    for(int i = 0; i < A.size(); i++) tar += A[i];
    //we have to sort either at begin or at end.
    sort(A.begin(), A.end(), greater<int>());
    solBook.clear();
    calculated.clear();
    vector<vector<bool>> trues( tar + 1, vector<bool> (A.size(), true));
    vector<vector<bool>> falses( tar + 1, vector<bool> (A.size(), false));
    long long int ctar; 
    bool found = false;
    //size 0 partition are not allowed.
    solBook.push_back(falses);
    calculated.push_back(trues);
    //size 1 partition will be some A[i] only.
    solBook.push_back(falses);
    calculated.push_back(falses);
    for(int i = 0; i < A.size(); i++) {
        solBook[1][A[i]][i] = true;
        calculated[1][A[i]][i] = true;
    }
    //we will find from 1 to n - 1  sized partition. break at smallest satisfying the
    //condition.
    int setSize = 0;
    int trigger = -1;
    int at = 0;
    for(int i = 0; i < A.size() - 1; i++) {
        solBook.push_back(falses);
        calculated.push_back(falses);
        ctar = tar * (i+1);
        if((ctar % A.size()) != 0) continue;
        ctar /= A.size();
        //now find if there is i+1 elements in A st their sum is ctar;
        //now do it iteratively over ind 0 to n - 1 s.t sum ctar of size i+1 is possible
        //by using only till 0 to ind elements.
        // found = isPossible(i + 1, ctar, ind) = case(incl A[ind])||case(not incl A[ind])
        // = isPossible(i + 1, ctar, ind-1) || isPossible(i, ctar - A[ind], ind - 1)
        for(int j = 0; j < A.size(); j++) {
            found = isPossible(i+1, ctar, j, A);
            if(found) {
                trigger = j;
                //break;
                //don't break as we need lexiographic smallest set 1.
		//we have sorted in descending order to pick larger elem first.
                //so we try to find largest size set2 first with smallest trailing element
		//(as we go till end)
		//so set1 have largest trailing elements in that size making leading elements small.
                
		//it won't work other way around as in ascending order and
		//breaking first won't see all elements and will force smallest
		//trailing elements making leading element larger (in sorted form).

		//if ascending order and go to last => it will give largest size set with smaller
		//trailing elements---> bad.
		//if descending and break ---> also bad. picked smallest size but with large starters
		//and didn't saw all elements esp smaller.
            }
        }
        if(found) {
            setSize = i + 1;
            at = ctar;
            //break;
        }
    }
    if(setSize > 0) {
        vector<bool> set2 (A.size(), false);
        //traceback;
        while(setSize > 0) {
            if(trigger == 0 || solBook[setSize][at][trigger - 1] != true) {
                set2[trigger] = true;
                setSize--;
                at -= A[trigger];
            }
            trigger--;
        }
        vector<int> B, C;
        for(int i = A.size() - 1; i >= 0; i--) {
            if(set2[i]) B.push_back(A[i]);
            else C.push_back(A[i]);
        }
        ans.push_back(C);
        ans.push_back(B);
    }
    return ans;
}
/*
if trailing elements are larger then the leading elements would be smaller for same avg of same size.
hence it would be lexio smaller.

guide:---->
break: didn't see all elements no gaurentee.: smallest set but of mid- lexiography:
case ascending: you missed the larger trailing elements for same size
case descending: you missed smaller elements which would have introduce larger trailing
		elements which are not picked till now.

ascending went till last:
finds largest size set having largest trailing elements. (As those cases would come at last).
so lexiographically not smallest due to size. no gaurentee of lexio largest.

descending went till last:
finds largest size set having smallest trailing elements. (As those cases would come at last).
so lexiographically largest. so other set will be smallest.

*/
int Solution::climbStairs(int A) {
    if(A < 1) return 1;
    if(A == 2) return 2;
    int steps[A + 1] = {1};
    //basecase steps[0] = 1;
    steps[1] = 1;
    steps[2] = 2;
    for(int i = 3; i <= A; i++) {
        steps[i] = steps[i - 1] + steps[i - 2];
    }
    return steps[A];
}
//fibonnaci number. here it is O(A) but can also be done in O(log(A));
//also space required can be reduced to O(1) in both case.
//sketch for O(log A): 
// |steps[A]   | = | 1  1 | x |steps[A - 1]| = { (| 1  1 |) ^ (A - 1) } x | 1 |
// |steps[A- 1]|   | 0  1 |   |steps[A - 2]|     (| 0  1 |)               | 1 |
// now (something of constant dimension)^A can be calculated in log(A). 
// (by diving power by 2 nd handling odd even powers).
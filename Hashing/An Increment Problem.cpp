vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,int >umap;
    for(int i=0;i<A.size();i++)
    {
        if(umap.find(A[i])!=umap.end())
        {
            A[umap[A[i]]]+=1;
            umap[A[i]+1]=umap[A[i]];
            umap[A[i]]=i;
        }
        else
        umap[A[i]] =i;
    }
    return A;
}
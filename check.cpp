#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &arr, vector<int> &segement_tree, int start, int low, int high){
    if(low==high){
        segement_tree[start] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    build(arr, segement_tree, start*2+1, low, mid);
    build(arr, segement_tree, start*2+2, mid+1, high);
    segement_tree[start] = max(segement_tree[start*2+1], segement_tree[start*2+2]);
    return;
}

int query(vector<int> &st, int index, int s,int e,int low, int high){
    // complety lies inside
    if(low>e || high<s)return INT_MIN;
    if(low<=s && high>=e)return st[index];
    return max(query(st, index*2+1, s, (s+e)/2, low, high), query(st, index*2+2, (((s+e)/2)+1), e, low, high));
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> segementtree(4*n+1);
    build(arr, segementtree, 0, 0 , n-1);
    int q;
    cin>>q;
    while(q--){
        int p,  q;
        cin>>p>>q;
        cout<<query(segementtree, 0, 0, n-1, p, q);
        cout<<" ";
    }
    cout<<endl<<endl;
}
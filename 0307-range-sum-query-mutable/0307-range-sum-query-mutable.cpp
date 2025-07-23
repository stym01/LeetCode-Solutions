



class NumArray {
public:
    vector<int>arr;
    vector<int>seg;
    int n;

    void build(int ind,int low,int high){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }

        int mid=(low+high)/2;
        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        seg.resize(4*n+1);
        build(0,0,n-1);
    }

    

    int qquery(int ind,int low,int high,int l,int r){ //l,r given in query and low,high taking the 0,n-1 in starting
        //no overlap means return 1e9;
        // l r , low,high or low high, l r
        if(r<low || high<l) return 0;

        //complete overlap means return the min value of this interval from seg [ind]
        //l low high r
        if(low>=l && high<=r) return seg[ind];

        //partial overlap
        int mid=(low+high)/2;
        
        int left=qquery(2*ind+1,low,mid,l,r);
        int right=qquery(2*ind+2,mid+1,high,l,r);

        return left+right;
    }

    void updatee(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind]=val;
            return;
        }

        int mid=(low+high)/2;
        if(i<=mid){
            updatee(2*ind+1,low,mid,i,val);
        }
        else updatee(2*ind+2,mid+1,high,i,val);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    
    void update(int index, int val) {
        updatee(0,0,n-1,index,val);
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        return qquery(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
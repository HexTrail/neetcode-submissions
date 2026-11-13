#define MAX 35000
class MinStack {
public:
    int t;
    int arr[MAX];
    MinStack() {
        t = -1;
    }
    
    void push(int val) {
        arr[++t] = val;
    }
    
    void pop() {
        t--;
    }
    
    int top() {
        return arr[t];
    }
    
    int getMin() {
        int min = INT_MAX;
        for(int i=0;i<=t;i++){
            if(arr[i]<min) min = arr[i];
        }
        return min;
    }
};

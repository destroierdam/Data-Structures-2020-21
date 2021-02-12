#include <iostream>
#include <stack>

void nextGreater(int arr[], int length){
    
    std::stack<int> s;
    //s.push(arr[0]);

    for(int i = 0; i < length; ++i){
        while (!s.empty() && arr[i] > s.top()){
            std::cout << s.top() << " -> " << arr[i] << "\n";
            s.pop();
        }
        s.push(arr[i]);
    }

    while(!s.empty()) {
        std::cout << s.top() << " -> " << "-1\n";
        s.pop();
    }
}
int main() {
    int arr[] = { 1, 2, 3, 4, 3, 2, 1, 2, 34, 55 };
    size_t sz = sizeof(arr)/sizeof(int);

    nextGreater(arr, sz);
    return 0;
}



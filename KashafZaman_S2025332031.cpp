#include <iostream>
using namespace std;

// Q1 – THEORY 

// Q1.A.1
// Contiguous memory allocation means storing elements in consecutive memory locations.
// Arrays use it so that elements can be accessed directly using index.
// This provides O(1) access time because address = base + index.

// Q1.A.2
// A memory leak occurs when dynamically allocated memory is not deleted.
// Example: int* arr = new int[10]; if we forget delete[] arr;, memory is wasted.

// Q1.A.3
// Static array has fixed size decided at compile time.
// Dynamic array can change size at runtime.
// Fixed size matters because it limits flexibility and memory usage.

// Q1.A.4
// Array access is O(1) because elements are directly indexed.
// Linked list requires traversal, so access is O(n).

//  Q1 – CODE 

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

void findMinMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = arr[0];
    maxVal = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] < minVal)
            minVal = arr[i];
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
}

// Q2 – THEORY 

// Q2.A.1
// Bubble Sort compares adjacent elements and swaps them if needed.
// Largest element moves to the end in each pass, like a bubble rising.

// Q2.A.2
// Best: O(n), Average: O(n^2), Worst: O(n^2)
// With optimization, best case becomes O(n) if already sorted.

// Q2.A.3
// Selection Sort is generally preferred because it does fewer swaps.
// Bubble Sort is easier to understand and implement.

//  Q2 – CODE 

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " "<<endl;
    
}

void bubbleSort(int arr[], int size, int &swapCount) {
    swapCount = 0;

    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapCount++;
                swapped = true;
            }
        }

        cout << "After pass " << i+1 << ": ";
        printArray(arr, size);

        if(!swapped)
            break;
    }
}

// Q3 – THEORY 

// Q3.A.1
// Array must be sorted for Binary Search to work correctly.

// Q3.A.2
// low=0, high=7 -> mid=3 -> arr[3]=12
// low=4, high=7 -> mid=5 -> arr[5]=23 (found)

// Q3.A.3
// Binary Search: O(log n), Linear Search: O(n)
// Binary reduces search space by half each step, making it faster.

// Q3 – CODE 

int binarySearch(int arr[], int size, int key, int &iterations) {
    int low = 0, high = size - 1;
    iterations = 0;

    while(low <= high) {
        iterations++;
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Q4 – THEORY

// Q4.A.1
// Big O describes algorithm growth rate.
// It is used instead of seconds because hardware differs.

// Q4.A.2
// Big O = worst case, Big Omega = best case, Big Theta = average case.
//  Example using Linear Search:
// Big O (Worst Case):
// When the element is at the last position or not present at all.
// We have to check all n elements → O(n)
//
// Big Omega (Best Case):
// When the element is at the first position.
// Only 1 comparison is needed → Ω(1)
//
// Big Theta (Average Case):
// On average, the element is found somewhere in the middle.
// About n/2 comparisons → Θ(n)

// Q4.A.3
// Fastest to slowest: O(1), O(log n), O(n), O(n log n), O(n^2)

// Q4.A.4
// Space complexity measures memory usage.
// If array of size n is created → O(n).

// Q4.A.5
// Incorrect. For large n, O(n log n) is always better than O(n^2).

// Q4 – CODE

// Nested loop → O(n^2)
void nestedLoop(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i] << " ";
        }
    }
}

// Single loop → O(n)
void singleLoop(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "<<endl;
    }
}

// O(n^2) function
bool checkElements(int A[], int B[], int n) {
    for(int i = 0; i < n; i++) {
        bool found = false;
        for(int j = 0; j < n; j++) {
            if(A[i] == B[j]) {
                found = true;
                 break;
            }
        }
        if(!found)
            return false;
    }
    return true;
}

//  Q5 – THEORY 

// Q5.A.1
// A singly linked list stores nodes connected by pointers.
// Unlike arrays, memory is not contiguous.

// Q5.A.2
// Insert head: O(1)
// Insert tail: O(n)
// Delete: O(n)

// Q5.A.3
// Not deleting node causes memory leak.
// Avoid by using delete.

// ===================== Q5 – CODE =====================

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node{val, nullptr};

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteByValue(int val) {
        if(head == nullptr) return;

        if(head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if(temp->next == nullptr) {
            cout << "Value not found"<<endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void display() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }
};

// MAIN 

int main() {

    // Q1
    cout << " Q1: Arrays and Searching "<<endl;

    int arr1[10] = {4,15,7,23,1,9,42,18,6,30};
    int index = linearSearch(arr1, 10, 42);

    if(index != -1)
        cout << "42 found at index: " << index << endl;
    else
        cout << "Not found"<<endl;

    int minVal, maxVal;
    findMinMax(arr1, 10, minVal, maxVal);
    cout << "Min: " << minVal << " Max: " << maxVal << endl;


    // Q2
     cout << " Q2: Bubble Sort "<<endl;
    int arr2[7] = {64,34,25,12,22,11,90};
    cout << "Before sorting: ";
    printArray(arr2, 7);

    int swaps;
    bubbleSort(arr2, 7, swaps);
    cout << "Total swaps: " << swaps << endl;


    // Q3
     cout << " Q3: Binary Search "<<endl;
    int arr3[10] = {2,5,8,12,16,23,38,45,56,72};
    int iterations;

    int result = binarySearch(arr3, 10, 56, iterations);
    cout << "Binary Search found at index: " << result;
    cout << " in " << iterations << " iterations";

    int result2 = binarySearch(arr3, 10, 100, iterations);
    cout << "Search for 100 result: " << result2;
    cout << " in " << iterations << " iterations";


    // Q4
      cout <<"Q4: Complexity Functions"<<endl;
    int arr4[3] = {1,2,3};
    nestedLoop(arr4, 3);
    cout << endl;
    singleLoop(arr4, 3);
    cout << endl;


    // Q5
     cout << "Q5: Linked List"<<endl;
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtHead(1);

    cout << "Linked List: ";
    list.display();

    list.deleteByValue(20);
    list.deleteByValue(100);

    cout << "After deletion: ";
    list.display();

    return 0;
}

// GitHub: https://github.com/kashafzaman/DSA-Arrays-Sorting-Searching
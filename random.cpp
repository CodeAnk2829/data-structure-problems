#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief Determines the maximum size of a high-priority subset of events.
 * * A subset is high-priority if at least one event in it overlaps/intersects
 * with every other event in the subset.
 * * @param start Array of event start times.
 * @param finish Array of event finish times.
 * @return int The length of the largest high-priority subset of events.
 */
int getSubsetLength(vector<int> start, vector<int> finish)
{
    int n = start.size();
    if (n == 0)
    {
        return 0;
    }

    // 1. Combine events into pairs (start, finish) for clarity, though
    // it's not strictly necessary. The original arrays are used directly.

    // 2. Initialize the maximum subset size found so far.
    int max_subset_size = 0;

    // 3. Iterate through every event k, treating it as the potential
    //    'central' event Ck that must intersect all others in the subset.
    for (int k = 0; k < n; ++k)
    {
        int current_subset_size = 0;

        // The central event Ck is [start[k], finish[k]]
        int c_start = start[k];
        int c_finish = finish[k];

        // 4. Count all events j that intersect with the central event Ck.
        for (int j = 0; j < n; ++j)
        {
            // Event Ej is [start[j], finish[j]]
            int e_start = start[j];
            int e_finish = finish[j];

            // Intersection condition:
            // Two intervals [A_start, A_finish] and [B_start, B_finish] intersect
            // if A_start <= B_finish AND B_start <= A_finish.

            // Note: The problem states "overlap at their start or end times are considered to intersect",
            // which confirms the use of non-strict inequality (<=).
            bool intersects = (c_start <= e_finish) && (e_start <= c_finish);

            if (intersects)
            {
                // If event j intersects with the central event k, it belongs
                // to the high-priority subset led by event k.
                current_subset_size++;
            }
        }

        // 5. Update the overall maximum size.
        max_subset_size = max(max_subset_size, current_subset_size);
    }

    return max_subset_size;
}

// --- Test Cases from the Images ---

/*
Example 1 (from image 2):
n = 4
start = [1, 2, 3, 4]
finish = [2, 3, 5, 6]
Events: E0=[1, 2], E1=[2, 3], E2=[3, 5], E3=[4, 6]
Expected Output: 3 (Subset: {E1, E2, E3} = {[2, 3], [3, 5], [4, 6]}, where E2=[3, 5] intersects all)
*/
void test_case_1()
{
    vector<int> start = {1, 2, 3, 4};
    vector<int> finish = {2, 3, 5, 6};
    int result = getSubsetLength(start, finish);
    cout << "Test Case 1 (Image Example):" << endl;
    cout << "Input: start=[1, 2, 3, 4], finish=[2, 3, 5, 6]" << endl;
    cout << "Expected: 3, Actual: " << result << endl;
    cout << (result == 3 ? "PASS" : "FAIL") << endl;
    cout << "---" << endl;
}

/*
Example 2 (from image 1):
n = 5
start = [1, 3, 4, 6, 9]
finish = [2, 8, 5, 7, 10]
Events: E0=[1, 2], E1=[3, 8], E2=[4, 5], E3=[6, 7], E4=[9, 10]
Expected Output: 3 (Subset: {E1, E2, E3} = {[3, 8], [4, 5], [6, 7]}, where E1=[3, 8] intersects all)
*/
void test_case_2()
{
    vector<int> start = {1, 3, 4, 6, 9};
    vector<int> finish = {2, 8, 5, 7, 10};
    int result = getSubsetLength(start, finish);
    cout << "Test Case 2 (Image 1 Sample):" << endl;
    cout << "Input: start=[1, 3, 4, 6, 9], finish=[2, 8, 5, 7, 10]" << endl;
    cout << "Expected: 3, Actual: " << result << endl;
    cout << (result == 3 ? "PASS" : "FAIL") << endl;
    cout << "---" << endl;
}

/*
Example 3 (from image 3):
n = 5
start = [1, 2, 4] (Note: Only 3 elements here, assuming n=3 from start array size, or the input is incomplete)
finish = [7, 5, 6] (We'll assume n=3: start=[1, 2, 4], finish=[7, 5, 6])
Events: E0=[1, 7], E1=[2, 5], E2=[4, 6]
Expected Output: 3 (Subset: {E0, E1, E2} = {[1, 7], [2, 5], [4, 6]}, where E1=[2, 5] intersects all)
*/
void test_case_3()
{
    vector<int> start = {1, 2, 4};
    vector<int> finish = {7, 5, 6};
    int result = getSubsetLength(start, finish);
    cout << "Test Case 3 (Image 3 Sample):" << endl;
    cout << "Input: start=[1, 2, 4], finish=[7, 5, 6]" << endl;
    cout << "Expected: 3, Actual: " << result << endl;
    cout << (result == 3 ? "PASS" : "FAIL") << endl;
    cout << "---" << endl;
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    return 0;
}
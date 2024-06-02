#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if we can place C elements with at least minDist distance apart
bool canPlaceCows(vector<int>& positions, int N, int C, int minDist) {
    int count = 1; // Place the first element at the first position
    int lastPosition = positions[0]; // Track the position of the last placed element
    
    for (int i = 1; i < N; ++i) {
        if (positions[i] - lastPosition >= minDist) {
            ++count; // Place the element
            lastPosition = positions[i]; // Update the last placed element
            if (count == C) return true; // If we've placed C elements, we're done
        }
    }
    return false; // If we can't place C elements, return false
}

// Function to find the maximum minimum distance
int findMaxDistance(vector<int>& positions, int N, int C) {
    sort(positions.begin(), positions.end()); // Sort the positions
    
    int lo = 0;
    int hi = positions[N-1] - positions[0]; // Max possible distance
    int maxDist = 0;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Midpoint of current search range
        cout<<lo<<' '<<hi<<' '<<mid<<' ';
        if (canPlaceCows(positions, N, C, mid)) {
            maxDist = mid; // If mid is feasible, it's our current best solution
            lo = mid + 1; // Try for a larger distance
        } else {
            hi = mid - 1; // Try for a smaller distance
        }
    }
    
    return maxDist; // Return the best found distance
}

int main() {
    freopen("input.txt","r", stdin);
    int T;
    cin >> T; // Number of test cases
    
    while (T--) {
        int N, C;
        cin >> N >> C; // Read N and C
        vector<int> positions(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> positions[i]; // Read the positions
        }
        
        int result = findMaxDistance(positions, N, C);
        cout << result << endl; // Output the result for each test case
    }
    
    return 0;
}

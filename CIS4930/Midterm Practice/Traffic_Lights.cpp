#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    // Insert base elements (initial distance of n, initial lights and the beginning and end of the street)
    multiset<int> distances;
    distances.insert(n);
    set<int> lights;
    lights.insert(0);
    lights.insert(n);
    for (int i = 0; i < l; i++) {
        int li;
        cin >> li;
        // Find streetlights above and below the one about the be inserted
        auto above = lights.upper_bound(li);
        auto below = prev(above);
        // Erase the distance where you are about to insert a light
        distances.erase(distances.find(*above - *below));
        // Insert the light and distance between it and the lights above and below it   
        lights.insert(li);
        distances.insert(*above - li);
        distances.insert(li - *below);
        // Get the greatest distance
        cout << *prev(distances.end()) << " ";
    }
    return 0;
} 
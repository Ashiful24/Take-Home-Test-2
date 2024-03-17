#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Function to calculate the distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to check if a set of points forms a square
bool isSquare(const vector<Point>& points) {
    if (points.size() != 4) return false;

    unordered_set<double> distances;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            distances.insert(distance(points[i], points[j]));
        }
    }

    return distances.size() == 2; // In a square, there are only two unique distances: side length and diagonal length
}

// Function to find if any 4 points form a square
bool findSquare(const vector<Point>& coordinates) {
    int n = coordinates.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    vector<Point> points{ coordinates[i], coordinates[j], coordinates[k], coordinates[l] };
                    if (isSquare(points)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<Point>> testCases = {
        {{0, 0}, {2, 0}, {1, 1}, {0, -1}, {-1, -1}, {0, 2}, {0, 1}, {1, 0}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 0}}, // Square with side length 1
        {{0, 0}, {1, 0}, {1, 1}, {0, 1}}, // Square with side length 1
        {{0, 0}, {2, 0}, {2, 2}, {0, 2}}, // Square with side length 2
        {{0, 0}, {1, 2}, {3, 1}, {2, -1}}, // Square with diagonal length sqrt(10)
        {{0, 0}, {1, 1}, {2, 2}, {3, 3}} // Not a square
    };

    for (const auto& coordinates : testCases) {
        if (findSquare(coordinates)) {
            cout << "Found a square!" << endl;
        }
        else {
            cout << "No square found." << endl;
        }
    }

    return 0;
}

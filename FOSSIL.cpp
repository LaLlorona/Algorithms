
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct point {
    double y, x;
};

vector<point> hull1, hull2;

int num_points_hull1, num_points_hull2;

vector<pair<point, point> > upper, lower;


void decompose(const vector<point>& hull) {
    int num_points = hull.size();
    
    for (int i = 0; i < num_points; i++) {
        if (hull[(i + 1) % num_points].x > hull[i].x) { // lower hull
            lower.push_back(make_pair(hull[i], hull[(i + 1) % num_points]));
        }
        if (hull[(i + 1) % num_points].x < hull[i].x) { // upper hull
            upper.push_back(make_pair(hull[i], hull[(i + 1) % num_points]));
        }
    }
    
}

bool IsXBetweenSegment(double x, pair<point, point> segment) {
    return (segment.first.x <= x && segment.second.x >= x) || (segment.second.x <= x && segment.first.x >= x);
}

double XMeetSementAt(double x, pair<point, point> segment) {
    point first = segment.first;
    point second = segment.second;
    return first.y + (second.y - first.y) * (x - first.x) / (second.x - first.x);
}

double vertical(double x) {
    double minimum_upper = 1e20;
    double maximum_lower = -1e20;
    for (int i = 0; i < upper.size(); i++) {
        if (IsXBetweenSegment(x, upper[i])) {
            minimum_upper = min(minimum_upper,XMeetSementAt(x,upper[i]));
        }
    }
    
    for (int i = 0; i < lower.size(); i++) {
        if (IsXBetweenSegment(x, lower[i])) {
            maximum_lower = max(maximum_lower,XMeetSementAt(x,lower[i]));
        }
    }
    return minimum_upper - maximum_lower;
}

double MaxX(vector<point> &hull) {
    double max_x = hull[0].x;
    for (int i = 0; i < hull.size(); i++) {
        max_x = max(max_x, hull[i].x);
    }
    return max_x;
}
double MinX(vector<point> &hull) {
    double min_x = hull[0].x;
    for (int i = 0; i < hull.size(); i++) {
        min_x = min(min_x, hull[i].x);
    }
}
double TrisectionSearch() {
    double lo = max(MinX(hull1), MinX(hull2));
    double hi = min(MaxX(hull1), MaxX(hull2));
    
    if (hi < lo) {
        return 0;
    }
    
    for (int iter = 0; iter < 100; iter++) {
        double aab = (lo * 2 + hi) /3.0;
        double abb = (lo * 2 + hi) /3.0;
        
        if (vertical(aab) < vertical(abb)) {
            lo = aab;
        }
        else{
            hi = abb;
        }
        
    }
    return max(0.0, vertical(hi));
}
int main()
{
    int num_testcase;
    double x;
    double y;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        hull1.clear();
        hull2.clear();
        upper.clear();
        lower.clear();
        cin >> num_points_hull1;
        cin >> num_points_hull2;
        for (int j = 0; j < num_points_hull1; j++) {
            cin >> x;
            cin >> y;
            hull1.push_back(point{y, x});
        }
        for (int k = 0; k < num_points_hull2; k++) {
            cin >> x;
            cin >> y;
            hull2.push_back(point{y, x});
        }
        decompose(hull1);
        decompose(hull2);
        cout << TrisectionSearch() << endl;
    }
    

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int Area(Point l1, Point r1, Point l2, Point r2){
    int x_dist=min(r1.x, r2.x)-max(l1.x, l2.x);
    int y_dist=min(r1.y, r2.y)-max(l1.y, l2.y);
    int dientich=0;
    if (x_dist > 0 && y_dist > 0) {
        dientich=x_dist*y_dist;
        return dientich;
    }
    else if (x_dist < 0 || y_dist < 0) return 0;
}

int main() {
    Point l1;
    cin >> l1.x >> l1.y;
    Point r1;
    cin >> r1.x >> r1.y;
    Point r2;
    cin >> r2.x >> r2.y;
    Point l2;
    cin >> l2.x >> l2.y;
    
    if (l1.x > r1.x) swap(l1.x, r1.x);
    if (l1.y > r1.y) swap(l1.y, r1.y);

    if (l2.x > r2.x) swap(l2.x, r2.x);
    if (l2.y > r2.y) swap(l2.y, r2.y);    
    cout << Area(l1, r1, l2, r2);
    return 0;

}
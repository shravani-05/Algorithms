#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
};

int orientation(Point p,Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0 ) return 0;
    return (val > 0) ? 1 : 2;
}
vector<Point> convexHull(vector<Point> &points){
    int n = points.size();
    if(n < 3){
        cout<<"Convex hull cannot be formed";
        return {};
    }
    

    vector<Point> hull;
    int leftmost = 0;
    for(int i = 0; i < n; i++){
        if(points[i].x < points[leftmost].x){
            leftmost = i;
        }
    }
    
    int p = leftmost,q;

    do{
        hull.push_back(points[p]);

        q= (p+1)%n;
        for(int i = 0; i < n; i++){
            if(orientation(points[p], points[i], points[q]) == 2){
                q = i;
            }
        }
        p=q;
    }
    while( p != leftmost);

    return hull;
}
int main(){
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<Point> hull = convexHull(points);

    cout<<"Points in the hull are: ";
    cout<<endl;
    for(const auto pt : hull){
        cout<<pt.x<<","<<pt.y;
        cout<<endl;
    }
    return 0;
}
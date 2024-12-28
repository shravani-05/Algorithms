#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};
Point p0;

Point nextToTop(stack<Point> &S){
    Point currentTop = S.top();
    S.pop();
    Point nextTop = S.top();
    S.push(currentTop);
    return nextTop;
}
int dist(Point p1, Point p2){
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); 
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}
bool compare(Point p1, Point p2){
    int o = orientation(p0,p1,p2);
    if(o == 0){
        return dist (p0,p1) < dist(p0,p2);
    }
    return (o == 2);
}
vector <Point> convexhull(vector<Point>& points){
    int n = points.size();
    if(n <3){
        cout<<"COnvex hull not possible";
        return {};
    }

    //this part of code is to find the lowest point
    int minY = 0;
    for(int i = 1; i < n; i++){
        if (points[i].y < points[minY].y || (points[i].y == points[minY].y && points[i].x < points[minY].x)){
            minY = i;
        }
    }

    swap(points[0], points[minY]);
    p0 = points[0];

    sort(points.begin() + 1, points.end(),compare);

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for(int i = 3; i < n ;i++){
        while(orientation(nextToTop(S),S.top(),points[i]) != 2){
            S.pop();
        }
        S.push(points[i]);
    } 

    vector<Point> hull;
    while(!S.empty()){
        hull.push_back(S.top());
        S.pop();
    }
    return hull;
}
int main(){
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<Point> hull = convexhull(points);

    cout<<"Points in the hull are :";
    cout<<endl;
    for(const auto &pt : hull){
        cout<<pt.x<<","<<pt.y;
        cout<<endl;
    }
}
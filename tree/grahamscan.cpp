#include<bits/stdc++.h>
using namespace std;

struct point2d{
     int x,y;
};

struct point2d initalPoint;

int calDist(struct point2d point1 , struct point2d point2){
   return (point1.x - point2.x) *(point1.x - point2.x) + (point1.y - point2.y) *(point1.y - point2.y);
}

int getOrigination(struct point2d p , struct point2d q, struct point2d r){
    int distance = (q.y - p.y)* (r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(distance == 0){
        return 0;
    }
    return (distance > 0) ? 1:2;
}

int compareFun(const void *pt1, const void *pt2){
    struct point2d *p1 = (struct point2d *)pt1;
    struct point2d *p2 = (struct point2d *)pt2;

    int i = getOrigination(initalPoint, *p1, *p2);

    if(i == 0) {
        return (calDist(initalPoint, *p2) >= calDist(initalPoint, *p1)) ? -1 : 1;
    }
    return ( i == 2) ? -1 : 1;
}

point2d getStack2top(vector<point2d> &stack){
    return stack[stack.size()-2];
}

void convexHull(struct point2d points[], int n){
    int ymin = points[0].y, min = 0;
    
    for(int i = 1; i < n; i++){
        int y = points[i].y;
        if( (y < ymin) || (y == ymin && points[i].x < points[min].x)){
            ymin = points[i].y;
            min = i;
        }
    }

    swap(points[0], points[min]);
    initalPoint = points[0];
    qsort(&points[1], n-1, sizeof(struct point2d), compareFun);

    int m = 1;

    for(int i = 1 ; i < n ; i++){
        while(i < n -1 && getOrigination(initalPoint, points[i], points[i+1]) == 0){
            i++;
        }

        points[m] = points[i];
        m++;
    }

    if(m < 3){
        return;
    }

    vector<point2d> stack;
    stack.push_back(points[0]);
    stack.push_back(points[1]);
    stack.push_back(points[2]);

    for(int i = 3; i < m; i++){
        while(getOrigination(getStack2top(stack),stack.back(), points[i]) != 2){
          stack.pop_back();
        } 
        stack.push_back(points[i]);
    }

    while(!stack.empty()){
       struct point2d p = stack.back();
       cout << p.x << " " << p.y << endl;
       stack.pop_back();
    }

}

int main(){
    struct point2d points[] = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {0, 0}, {2, 1}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points,n);
    return 0;
}
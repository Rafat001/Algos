#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
const double EPS=1e-10;
struct Point
{
    double x,y;

    Point() {}
    Point(double x, double y):x(x),y(y) {}
    Point(const Point &p): x(p.x),y(p.y) {}

    void input()
    {
        scanf("%lf%lf",&x,&y);
    }

    Point operator + (const Point &p) const
    {
        return Point(x+p.x, y+p.y);
    }

    Point operator - (const Point &p) const
    {
        return Point(x-p.x, y-p.y);
    }

    Point operator * (double c) const
    {
        return Point(x*c, y*c);
    }

    Point operator / (double c) const
    {
        return Point(x/c, y/c);
    }
};
Point RotateCCW90(Point p) // rotate 90 degree counter clockwise
{
    return Point(-p.y,p.x);
}
Point RotateCW90(Point p) // rotate 90 degree clockwise
{
    return Point(p.y,-p.x);
}
Point RotateCCW(Point p, double t)
{
    return Point(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}
Point RotateCW(Point p, double t)
{
    return Point(p.x*cos(t)+p.y*sin(t),-p.x*sin(t)+p.y*cos(t));
}
double dot(Point A, Point B)
{
    return A.x*B.x+A.y*B.y;
}
double cross(Point A, Point B)
{
    return A.x*B.y-A.y*B.x;
}
double dist2(Point A, Point B)
{
    return dot(A-B,A-B);
}
double distBetweenPoint(Point A, Point B) // Distance between point A and B
{
    return sqrt(dot(A-B,A-B));
}
Point ProjectPointLine(Point A, Point B, Point C)// project point c onto line AB (A!=B)
{
    return A+(B-A)*dot(C-A,B-A)/dot(B-A,B-A);
}
bool LinesParallel(Point A, Point B, Point C, Point D) // Determine if Line AB and CD are parallel or collinear
{
    return fabs(cross(B-A,C-D))<EPS;
}
bool LinesCollinear(Point A, Point B, Point C, Point D) // Determine if Line AB and CD are collinear
{
    return LinesParallel(A,B,C,D) && fabs(cross(A-B,A-C))<EPS && fabs(cross(C-D,C-A))<EPS;
}
bool SegmentIntersect(Point A, Point B, Point C, Point D) //checks if AB intersect with CD
{
    if(LinesCollinear(A,B,C,D))
    {
        if(dist2(A,C)<EPS || dist2(A,D)<EPS || dist2(B,C)<EPS || dist2(B,D)<EPS) return true;
        if(dot(C-A,C-B) > 0 && dot(D-A,D-B) > 0 && dot(C-B,D-B) > 0) return false;
        return true;
    }
    if(cross(D-A,B-A) * cross(C-A,B-A) > 0) return false;
    if(cross(A-C,D-C) * cross(B-C,D-C) > 0) return false;
    return true;
}
Point ComputeLineIntersection(Point A, Point B, Point C, Point D) // Compute the coordinates where AB and CD intersect
{
    double a1,b1,c1,a2,b2,c2;
    a1=A.y-B.y;
    b1=B.x-A.x;
    c1=cross(A,B);
    a2=C.y-D.y;
    b2=D.x-C.x;
    c2=cross(C,D);
    double Dist=a1*b2-a2*b1;
    return Point((b1*c2-b2*c1)/Dist,(c1*a2-c2*a1)/Dist);
}
Point ProjectPointSegment(Point A, Point B, Point C) //Project point C onto line segment AB -- return the Point from AB which is the closest to C --
{
    double r=dot(B-A,B-A);
    if(fabs(r)<EPS) return A;
    r=dot(C-A,B-A)/r;
    if(r<0) return A;
    if(r>1) return B;
    return A+(B-A)*r;
}
double DistancePointSegment(Point A, Point B, Point C) // return the minimum distance from a point C to a line AB
{
    return distBetweenPoint(C,ProjectPointSegment(A,B,C));
}
double distToLine(Point p, Point a, Point b) // return distance between P and a point where p is perpendicular on AB. AB er upore p jei point e lombo shei point theke p er distance
{
    pair<double,double>c;
    double scale=(double)(dot(p-a,b-a))/(dot(b-a,b-a));
    c.first=a.x+scale*(b.x-a.x);
    c.second=a.y+scale*(b.y-a.y);
    double dx=(double)p.x-c.first,dy=(double)p.y-c.second;
    return sqrt(dx*dx+dy*dy);
}
int main()
{

}

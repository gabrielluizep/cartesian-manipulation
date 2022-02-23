#include <math.h>
#include <stdio.h>

typedef struct {
    double x, y;
} cartesianPoint;

/*
  Random points generated using VSCode Extension "Random Everything"
*/

cartesianPoint points[100] = {
    {-409.7429, 833.653},  {57.5209, -239.1312},   {270.6567, -468.3047},
    {413.5635, 518.7526},  {-440.1733, -687.8157}, {-101.7035, 326.7127},
    {-886.9833, -7.7183},  {324.3432, 452.6857},   {-234.8968, 174.8439},
    {457.0519, -911.3039}, {706.6779, 916.9634},   {-176.4272, 551.2853},
    {489.3141, 655.7879},  {342.9555, -235.9018},  {419.5547, -934.6889},
    {487.6173, -804.5184}, {-833.28, 524.3581},    {997.2911, -558.5512},
    {789.1392, -162.7869}, {26.4961, -996.1414},   {456.1155, -130.1157},
    {-148.7112, 133.6947}, {-989.6235, -494.0339}, {319.5874, -610.7631},
    {98.9841, -250.1152},  {-678.9588, 849.4217},  {-561.5905, 600.6487},
    {-526.5273, 478.7154},
};

double distanceBetweenTwoPoints(cartesianPoint pointA, cartesianPoint pointB) {
    double xDistantce;
    if (pointA.x > pointB.x) {
        xDistantce = pointA.x - pointB.x;
    } else {
        xDistantce = pointB.x - pointA.x;
    }

    double yDistantce;
    if (pointA.y > pointB.y) {
        yDistantce = pointA.y - pointB.y;
    } else {
        yDistantce = pointB.y - pointA.y;
    }

    double totalDistance;
    totalDistance = sqrt(pow(xDistantce, 2) + pow(yDistantce, 2));

    return totalDistance;
}

/*
  @return
  0 - if point is on any axes (x or y beeing 0)
  1 - if the point is on first quadrant (top-rigth quadrant)
  2 - if the point is on the second quadrant (top-left quadrant)
  3 - if the point is on the thrid quadrant (bottom-left quadrant)
  4 - if the point is on the fourth quadrant (bottom-right quadrant)
*/

int identifyCartesianQuadrant(cartesianPoint point) {
    int quadrant;

    if (point.x == 0 || point.y == 0) {
        quadrant = 0;
    } else if (point.x > 0 && point.y > 0) {
        quadrant = 1;
    } else if (point.x < 0 && point.y > 0) {
        quadrant = 2;
    } else if (point.x < 0 && point.y < 0) {
        quadrant = 3;
    } else {
        quadrant = 4;
    }

    return quadrant;
}

int main() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf(
                "The distance between the points ( %.2lf ; %.2lf ) and ( "
                "%.2lf;%.2lf ) is "
                "%lf\n",
                points[i].x, points[i].y, points[j].x, points[j].y,
                distanceBetweenTwoPoints(points[i], points[j]));
        };
    }

    for (int i = 0; i < 20; i++) {
        printf("Point ( %.2lf ; %.2lf ) is on quadrant %d\n", points[i].x,
               points[i].y, identifyCartesianQuadrant(points[i]));
    }

    return 0;
}

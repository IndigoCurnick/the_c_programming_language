#include <stdio.h>
#include <math.h>

struct CartThree
{
    int x;
    int y;
    int z;
};

struct CartThree makecart(int x, int y, int z)
{
    struct CartThree temp;

    temp.x = x;
    temp.y = y;
    temp.z = z;

    return temp;
}

double dist(struct CartThree *c1, struct CartThree *c2)
{
    double x_dist = pow((double)c1->x - c2->x, 2.0);
    double y_dist = pow((double)c1->y - c2->y, 2.0);
    double z_dist = pow((double)c1->z - c2->z, 2.0);

    double sq = x_dist + y_dist + z_dist;

    return pow(sq, 0.5);
}

struct CartThree add(struct CartThree *c1, struct CartThree *c2)
{
    return makecart(c1->x + c2->x, c1->y + c2->y, c1->z + c2->z);
}

struct CartThree subtract(struct CartThree *c1, struct CartThree *c2)
{
    return makecart(c1->x - c2->x, c1->y - c2->y, c1->z - c2->z);
}

void display_cart_three(struct CartThree *c)
{
    printf("x: %d, y: %d, z: %d", c->x, c->y, c->z);
}

int main()
{

    struct CartThree c1 = makecart(5, 2, 3);
    struct CartThree c2 = makecart(2, 6, 7);

    printf("The two Vectors are:\n");
    printf("c1:");
    display_cart_three(&c1);
    printf("\nc2:");
    display_cart_three(&c2);
    printf("\n");

    printf("The distance between them is %f\n", dist(&c1, &c2));

    printf("Added they become: ");
    struct CartThree p = add(&c1, &c2);
    display_cart_three(&p);
    printf("\nSubtracted they become");
    struct CartThree v = subtract(&c1, &c2);
    display_cart_three(&v);
    printf("\n");

    return 0;
}
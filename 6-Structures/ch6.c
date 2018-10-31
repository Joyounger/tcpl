#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))
#define NKEYS 32 // the num of C keywords

struct key {
    char* word;
    int count
} keytab[] = {
    { "auto",     0 },
    { "break",    0 },
    { "case",     0 },
    { "char",     0 },
    { "const",    0 },
    { "continue", 0 },
    { "default",  0 },
    { "do",       0 },
    { "double",   0 },
    { "else",     0 },
    { "enum",     0 },
    { "extern",   0 },
    { "float",    0 },
    { "for",      0 },
    { "goto",     0 },
    { "if",       0 },
    { "int",      0 },
    { "long",     0 },
    { "register", 0 },
    { "return",   0 },
    { "short",    0 },
    { "signed",   0 },
    { "sizeof",   0 },
    { "static",   0 },
    { "struct",   0 },
    { "switch",   0 },
    { "typedef",  0 },
    { "union",    0 },
    { "unsigned", 0 },
    { "void",     0 },
    { "volatile", 0 },
    { "while",    0 }
};

int main(int argc, char const *argv[])
{
    struct point {
        int x;
        int y;
    }

    struct point pt = { 320, 200 };
    printf("%sd, %d\n", pt.x, pt.y);

    double dist;

    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("%f\n", dist);

    struct rect {
        struct point pt1;
        struct point pt2;
    }

    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);


    return 0;
}


// makepoint: make a point from x and y components
struct point makepoint(int x, int y)
{
    struct point pt;
    pt.x = x;
    pt.y = y;

    return pt;
}

// addpoint: add two points
struct point addpoint(struct point pt1, struct point pt2)
{
   pt1.x += pt2.x;
   pt1.y += pt2.y;

   return pt1;
}

// ptinrect: return 1 if pt in rt, 0 if not
int ptinrect(struct point pt, struct rect rt)
{
    if ((pt.x >= rt.pt1.x) && (pt.x < rt.pt2.x)
     && (pt.y >= rt.pt1.y) && (pt.y < rt.pt2.y)) {
        return 1;
    } else {
        return 0;
    }
}

struct rect canonrect(struct rect rt)
{
    struct rect tmp;

    tmp.pt1.x = min(rt.pt1.x, rt.pt2.x);
    tmp.pt1.y = min(rt.pt1.y, rt.pt2.y);
    tmp.pt2.x = max(rt.pt1.x, rt.pt2.x);
    tmp.pt2.y = max(rt.pt1.y, rt.pt2.y);

    return tmp;
}







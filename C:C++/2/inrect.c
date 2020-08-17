#include <stdio.h>
#include <math.h>

float min(float float1, float float2)
{
    if (float1 < float2)
    {
        
        return float1;
    }
    else
    {
        return float2;
    }
}

float max(float float1, float float2)
{
    if (float1 > float2)
    {
        return float1;
    }
    else
    {
        return float2;
    }
}

int InRectangle(float pt[2], float rect[4])
{
    if (pt[0] >= min(rect[0], rect[2]) && pt[0] <= max(rect[0], rect[2]) && pt[1] >= min(rect[1], rect[3]) && pt[1] <= max(rect[1], rect[3]))
    {
        return 1;
    }
        return 0;
}
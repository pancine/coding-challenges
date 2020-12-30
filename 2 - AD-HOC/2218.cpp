#include <iostream>

struct rectangle
{
    int x, y, u, v;
};

int Max(int, int);
int Min(int, int);
bool AintersectB(rectangle, rectangle);

int main()
{
    bool flag = true;
    int regionNumber = 1, limit, rectNumber, test = 1;
    rectangle intersection, actual;

    std::cin >> regionNumber;

    while (regionNumber > 0)
    {
        std::cin >> intersection.x >> intersection.y >> intersection.u >> intersection.v;

        for (rectNumber = 0; rectNumber < regionNumber - 1; rectNumber++)
        {
            std::cin >> actual.x >> actual.y >> actual.u >> actual.v;

            if (AintersectB(intersection, actual))
            {
                intersection.x = Max(intersection.x, actual.x);
                intersection.y = Min(intersection.y, actual.y);
                intersection.u = Min(intersection.u, actual.u);
                intersection.v = Max(intersection.v, actual.v);
            }
            else
            {
                for (int i = rectNumber + 1; i < regionNumber - 1; i++)
                {
                    std::cin >> actual.x >> actual.y >> actual.u >> actual.v;
                }
                flag = false;
                break;
            }
        }

        if (flag)
        {
            std::cout << "Teste " << test++ << "\n";
            std::cout << intersection.x << " " << intersection.y << " " << intersection.u << " " << intersection.v << "\n\n";
        }
        else
        {
            std::cout << "Teste " << test++ << "\n";
            std::cout << "nenhum\n\n";

            flag = true;
        }

        std::cin >> regionNumber;
    }

    return 0;
}

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int Min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

bool AintersectB(rectangle A, rectangle B)
{
    bool flagX = false, flagY = false;

    for (int x = A.x; x <= A.u; x++)
    {
        if (B.x <= x && x <= B.u)
        {
            flagX = true;
            break;
        }
    }
    for (int y = A.v; y <= A.y; y++)
    {
        if (B.v <= y && y <= B.y)
        {
            flagY = true;
            break;
        }
    }
    
    return (flagX && flagY);
}
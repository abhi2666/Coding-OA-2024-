#include <iostream>

using namespace std;

bool canAchievePiles(int a, int b, int c, int x, int y)
{
    // Check if x and y are within the total number of stones.
    if (x + y > a + b + c)
    {
        return false;
    }

    // Check if x or y is the original pile size.
    if (x == a || x == b || x == c && y == a || y == b || y == c)
    {
        return true;
    }

    // Analyze each pile as the chosen pile to split.
    for (int pile : {a, b, c})
    {
        // Calculate stones moved to each remaining pile for different split values (k).
        for (int k = 0; k <= pile; k++)
        {
            int remaining1 = (pile - k) + b;
            int remaining2 = k + c;

            // Check if remaining piles match x and y (order doesn't matter).
            if ((remaining1 == x && remaining2 == y) || (remaining1 == y && remaining2 == x))
            {
                return true;
            }
        }
    }

    // No combination achieved x and y.
    return false;
}

int main()
{
    int a = 2, b = 4, c = 2, x = 6, y = 2;

    if (canAchievePiles(a, b, c, x, y))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

//The highest building in our city has only one elevator. 
//A request list is made up with N positive numbers. 
//The numbers denote at which floors the elevator will stop, 
//in specified order. It costs 6 seconds to move the elevator up one floor, 
//and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

//For a given request list, you are to compute the total time spent 
//to fulfill the requests on the list. The elevator is on the 0th floor
// at the beginning and does not have to return to the ground floor when the requests are fulfilled.

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N && N)
    {
        int tot = 5 * N;
        int floor = 0;
        int req;
        for (int i = 0; i < N; i++)
        {
            cin >> req;
            if (req > floor)
            {
                tot += (req - floor) * 6;
            }
            else
            {
                tot += (floor - req) * 4;
            }
            floor = req;
        }
        cout << tot << '\n';
    }
    return 0;
}

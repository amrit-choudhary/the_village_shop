#include <iostream>
#include <thread>

#include "TimeManagement/TimeManager.h"

namespace
{
    const uint32_t runTimeSeconds = 10;
    double initPos = 0;
    double speed = 100; // 100 m/s;
}

int main(int argc, char **argv)
{

    std::cout << "Game Start!" << '\n';

    // Init global variables.
    TimeManager timeManager;
    timeManager.GameStart();

    while (true)
    {
        timeManager.Update();

        initPos += speed * timeManager.GetDeltaTime();

        if (timeManager.GetTimeSinceStartup() > runTimeSeconds)
        {
            break;
        }
    }

    timeManager.GameEnd();

    std::cout << "Final Pos: " << initPos << '\n';

    std::cout << "Game Run Time: " << timeManager.GetTimeSinceStartup() << '\n';
    std::cout << "Average FPS: " << timeManager.GetFrameCount() / timeManager.GetTimeSinceStartup() << '\n';
    std::cout << "Total Frames: " << timeManager.GetFrameCount() << '\n';
    std::cout << "Game Over!" << '\n';
}
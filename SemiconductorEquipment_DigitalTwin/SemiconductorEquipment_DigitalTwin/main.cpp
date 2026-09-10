#include "Robot.h"
#include <iostream>

int main()
{
    Robot robot;

    robot.Move(10, 20, 30);
    robot.MoveComplete();

    robot.Homing();

    return 0;
}
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/BlackChassis.h"
#include <frc/smartdashboard/SmartDashboard.h>

BlackChassis::BlackChassis(WPI_TalonFX& ID1, WPI_TalonFX& ID2, WPI_TalonFX& ID3, WPI_TalonFX& ID4) 
    :FrontRightWheel(ID1),
    BackRightWheel(ID2),
    FrontLeftWheel(ID3),
    BackLeftWheel(ID4),
    Drive(FrontRightWheel,FrontLeftWheel)
{
    BackRightWheel.Follow(FrontRightWheel);
    BackLeftWheel.Follow(FrontLeftWheel);
}

// This method will be called once per scheduler run
void BlackChassis::Periodic() {
    //gear ratio:14/62
    frc::SmartDashboard::PutNumber("SpeedRight(FeetPerSecond)", 12.57*FrontRightWheel.GetSelectedSensorVelocity()*(14/62)/12);
    frc::SmartDashboard::PutNumber("SpeedLeft(FeetPerSecond)", 12.57*FrontLeftWheel.GetSelectedSensorVelocity()*(14/62)/12);
    //(circumferance inches*rotations a second*gear ratio) / 12
}

void BlackChassis::TankDrive(double left, double right){
    Drive.TankDrive(left, right);
}
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/BlackChassis.h"

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
void BlackChassis::Periodic() {}

void BlackChassis::TankDrive(double left, double right){
    Drive.TankDrive(left, right);
}
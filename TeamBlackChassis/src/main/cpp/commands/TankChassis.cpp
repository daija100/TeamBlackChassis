// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankChassis.h"

TankChassis::TankChassis(BlackChassis& mDriveTrain, std::function<double()> left, std::function<double()> right)
:DriveTrain(mDriveTrain), Left(left), Right(right)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&DriveTrain);
}

// Called when the command is initially scheduled.
void TankChassis::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankChassis::Execute() {
  DriveTrain.TankDrive(Left(), Right());
}

// Called once the command ends or is interrupted.
void TankChassis::End(bool interrupted) {}

// Returns true when the command should end.
bool TankChassis::IsFinished() {
  return false;
}

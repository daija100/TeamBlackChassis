// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>

class BlackChassis : public frc2::SubsystemBase {
 public:
  BlackChassis(WPI_TalonFX& ID1, WPI_TalonFX& ID2, WPI_TalonFX& ID3, WPI_TalonFX& ID4);

  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  

  void TankDrive(double left, double right);
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX& FrontRightWheel;
  WPI_TalonFX& FrontLeftWheel;
  WPI_TalonFX& BackRightWheel;
  WPI_TalonFX& BackLeftWheel;
  frc::DifferentialDrive Drive;
};

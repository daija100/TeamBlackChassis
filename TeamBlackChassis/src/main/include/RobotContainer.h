// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include "commands/TankChassis.h"

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/BlackChassis.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

  frc2::CommandPtr GetAutonomousCommand();

  static constexpr int FRWheel{0};
  static constexpr int BRWheel{1};
  static constexpr int FLWheel{3};
  static constexpr int BLWheel{4};

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};
      frc::XboxController driver{0};



  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;

  WPI_TalonFX FrontRightWheel{FRWheel};
  WPI_TalonFX BackRightWheel{BRWheel};
  WPI_TalonFX FrontLeftWheel{FLWheel};
  WPI_TalonFX BackLeftWheel{BLWheel};
  BlackChassis DriveTrain{FrontRightWheel, BackRightWheel, FrontLeftWheel, BackLeftWheel};

  void ConfigureBindings();
};

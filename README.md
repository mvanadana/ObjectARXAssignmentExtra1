# ObjectARXAssignmentExtra1
## Work with System Variables and Use Commands
This ObjectARX application defines a function called "commandAndSysVar" that interacts with the CIRCLERAD system variable in AutoCAD. The function performs the following tasks:

1.Retrieves the current value of the CIRCLERAD system variable using acedGetVar and displays it using acutPrintf.
2.Defines a center point for a circle (pt) and a radius (rrad).
3.Executes the CIRCLE command with the provided values using acedCommandS.
4.Pauses for user input before completing the circle using the PAUSE option with another call to the CIRCLE command.
5.Sets the value of the CIRCLERAD system variable back to its original value using acedSetVar.

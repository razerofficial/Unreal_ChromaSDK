REM CHANGE THE CONSOLE TO YOUR DEVKIT IP
SET CONSOLE=192.168.1.176
SET PKG=3a50f0d0-133e-42de-a016-152c2f3b1b91_1.0.0.0_neutral__fm2vaa0rg472m
REM
REM
REM Copy the build folder to the \\192.168.1.176\DevelopmentFiles\3a50f0d0-133e-42de-a016-152c2f3b1b91_1.0.0.0_neutral__fm2vaa0rg472m folder and then run this script from there.
REM
REM
REM START THE INSTALL PROCESS
START "" "xbox-dev-install://*PackageName*//%CONSOLE%/DevelopmentFiles/%PKG%/%PKG%*Address*%CONSOLE%"

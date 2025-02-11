@echo off
echo Cleaning build files...

cd ..

:: Remove the build directory
if exist build (
    rmdir /s /q build
    echo Removed 'build' directory.
) else (
    echo 'build' directory not found.
)

:: Remove the bin directory in the project root
if exist bin (
    rmdir /s /q bin
    echo Removed 'bin' directory.
) else (
    echo 'bin' directory not found.
)

:: Add more folders or files to clean as needed
pause

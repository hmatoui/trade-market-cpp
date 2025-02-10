@echo off

SET BUILD_DIR=build
SET ARCH=x64

:: Navigate to the project root directory
cd ..

IF NOT EXIST %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

:: Run cmake to configure the project
cmake -B%BUILD_DIR% -A %ARCH% .

IF %ERRORLEVEL% NEQ 0 (
    echo CMake configuration failed!
    exit /b %ERRORLEVEL%
)

echo Building project...
:: Build the project using the build folder
cmake --build %BUILD_DIR% --config Release --target ALL_BUILD

IF %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b %ERRORLEVEL%
)

echo Build completed successfully!

pause

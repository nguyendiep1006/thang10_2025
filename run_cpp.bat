@echo off
echo Compiling %1...
g++ -std=c++11 -Wall -g %1 -o %~n1.exe
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b 1
)
echo Running %~n1.exe...
%~n1.exe
echo.
echo Program finished. Press any key to exit...
pause > nul

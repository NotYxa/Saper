@REM filepath: build.bat
@echo off
gcc -o minesweeper.exe main.c board.c game.c io.c scores.c -I. -Wall
if %ERRORLEVEL% EQU 0 (
    echo Build successful!
) else (
    echo Build failed!
)
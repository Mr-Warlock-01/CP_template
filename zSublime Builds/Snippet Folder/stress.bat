@echo off

if [%1]==[] (set /A numLoop = 100) else (set /A numLoop = %1)
if [%2]==[] (set /A doComp = 1) else (set /A doComp = %2)

if %doComp% equ 1 (
    echo Compiling ok, gen, brute...

    g++ -std=c++14 gen.cpp -o gen
    g++ -std=c++14 ok.cpp -o ok
    g++ -std=c++14 brute.cpp -o brute

    echo Done compiling.
)

set "diff_found="

for /l %%x in (1, 1, %numLoop%) do (
    echo Passed test:  %%x
    gen > input.in
    ok < input.in > output.out 
    brute < input.in > output2.out

    rem add \f after "fc" to ignore trailing whitespaces and to convert
    rem multiple whitespaces into one space
    fc output.out output2.out > diagnostics
    if errorlevel 1 (
        set "diff_found=y"
        goto :break
    )
)

:break

if defined diff_found (
    echo.
    echo Wrong Answer 
    echo.
    echo Input: 
    type input.in
    echo.
    echo.

    echo Output:
    type output.out
    echo.

    echo Expected:
    type output2.out
    echo.
) else  (
    echo.
    echo All tests passed Alhamdulillah!
)

del input.in
del output.out
del output2.out

REM 
REM  Windows Batch file to run examples
REM
SET PROG=build\example\Debug\example_runtime.exe
%PROG% 0 16 "data\eia\%%06d.png" "result\eia_result_%%02d.png" 16 2
%PROG% 0 8 "data\eia\%%06d.png" "result\eia_resulta_%%02d.png" 8 2
%PROG% 8 8 "data\eia\%%06d.png" "result\eia_resultb_%%02d.png" 8 2

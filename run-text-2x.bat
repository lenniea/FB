REM 
REM  Windows Batch file to run examples
REM
SET PROG=build\example\Debug\example_runtime.exe
%PROG% 0 30 "data\text\%%06d.png" "result\text_result_%%02d.png" 30 2
%PROG% 0 15 "data\text\%%06d.png" "result\text_resulta_%%02d.png" 15 2
%PROG% 15 15 "data\text\%%06d.png" "result\text_resultb_%%02d.png" 15 2

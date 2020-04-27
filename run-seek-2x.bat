REM 
REM  Windows Batch file to run examples
REM
SET PROG=build\example\Debug\example_runtime.exe
%PROG% 0 32 "data\seek\Data_%%04d.bmp" "result\seek_result_%%02d.png" 32 2
%PROG% 0 16 "data\seek\Data_%%04d.bmp" "result\seek_resulta_%%02d.png" 16 2
%PROG% 16 16 "data\seek\Data_%%04d.bmp" "result\seek_resultb_%%02d.png" 16 2

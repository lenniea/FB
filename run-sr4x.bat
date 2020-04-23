REM 
REM  Windows Batch file to run examples
REM
SET PROG=build\example\Debug\example_runtime
%PROG% 0 16 "data\eia\%%06d.png" "result\eia_4x4_result_%%02d.png" 16 4
%PROG% 0 82 "data\Emily\%%06d.png" "result\Emily_4x4_result_%%02d.png" 40 4
%PROG% 0 30 "data\text\%%06d.png" "result\text_4x4_result_%%02d.png" 20 4
%PROG% 0 61 "data\Adyoron\%%06d.png" "result\Adyoron_4x4_result_%%02d.png" 30 4

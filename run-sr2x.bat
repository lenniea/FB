REM 
REM  Windows Batch file to run examples
REM
SET PROG=build\example\Debug\example_runtime.exe
%PROG% 0 16 "data\eia\%%06d.png" "result\eia_result_%%02d.png" 16 2
%PROG% 0 8 "data\eia\%%06d.png" "result\eia_resulta_%%02d.png" 8 2
%PROG% 8 8 "data\eia\%%06d.png" "result\eia_resultb_%%02d.png" 8 2
%PROG% 0 82 "data\Emily\%%06d.png" "result\Emily_result_%%02d.png" 82 2
%PROG% 0 41 "data\Emily\%%06d.png" "result\Emily_resulta_%%02d.png" 41 2
%PROG% 41 41 "data\Emily\%%06d.png" "result\Emily__resultb_%%02d.png" 41 2
%PROG% 0 30 "data\text\%%06d.png" "result\text_result_%%02d.png" 30 2
%PROG% 0 15 "data\text\%%06d.png" "result\text_resulta_%%02d.png" 15 2
%PROG% 15 15 "data\text\%%06d.png" "result\text_resultb_%%02d.png" 15 2
%PROG% 0 61 "data\Adyoron\%%06d.png" "result\Adyoron_result_%%02d.png" 61 2
%PROG% 0 30 "data\Adyoron\%%06d.png" "result\Adyoron_resulta_%%02d.png" 30 2
%PROG% 30 30 "data\Adyoron\%%06d.png" "result\Adyoron_resultb_%%02d.png" 30 2

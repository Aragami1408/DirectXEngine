@ECHO off
SetLocal EnableDelayedExpansion
IF NOT EXIST bin mkdir bin
IF NOT EXIST bin\int mkdir bin\int

call vcvarsall.bat x64
SET cc=cl.exe

SET c_filenames= 
FOR %%f in (*.cpp) do SET c_filenames=!c_filenames! %%f

SET compiler_flags=/Zc:preprocessor /wd4090 /wd5105 /EHsc /MP /Ot /std:c++latest
SET linker_flags=/link /DEBUG /SUBSYSTEM:WINDOWS shell32.lib user32.lib winmm.lib userenv.lib gdi32.lib
SET output=/Fe.\bin\DXGame /Fo.\bin\int\ /MT /fp:fast
SET defines=/D_CRT_SECURE_NO_WARNINGS

ECHO Building DXEngine...
%cc% %compiler_flags% %c_filenames% %defines% %output% %linker_flags%
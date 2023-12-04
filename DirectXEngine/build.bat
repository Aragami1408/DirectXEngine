@ECHO off
SetLocal EnableDelayedExpansion
IF NOT EXIST bin mkdir bin
IF NOT EXIST bin\int mkdir bin\int

call vcvarsall.bat x64
SET cc=cl.exe

SET c_filenames=
FOR %%f in (*.cpp) do SET c_filenames=!c_filenames! %%f

SET compiler_flags=/ZI /JMC /nologo /W1 /WX- /diagnostics:column /MP /Od /Ot /Zc:preprocessor- /Gm- /EHsc /RTC1 /MT /GS /fp:fast /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++latest /external:W1 /Gd /TP /FC /errorReport:prompt
SET linker_flags=/link /DEBUG /SUBSYSTEM:WINDOWS shell32.lib user32.lib winmm.lib userenv.lib gdi32.lib d3d11.lib kernel32.lib winspool.lib comdlg32.lib advapi32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
SET output=/Fe.\bin\DXGame /Fo.\bin\int\

ECHO Building DXEngine...
%cc% %compiler_flags% %c_filenames% %output% %linker_flags%

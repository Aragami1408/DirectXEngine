@ECHO off
SetLocal EnableDelayedExpansion
IF NOT EXIST bin mkdir bin
IF NOT EXIST bin\int mkdir bin\int

call vcvarsall.bat x64
SET cc=cl.exe

SET c_filenames= 
FOR %%f in (*.c) do SET c_filenames=!c_filenames! %%f

if %cc% == cl.exe (
  SET compiler_flags=/Zc:preprocessor /wd4090 /wd5105
  SET include_flags=/I.\source\ /I.\third_party\include\ /I.\third_party\source\
  SET linker_flags=/link /DEBUG shell32.lib user32.lib winmm.lib userenv.lib gdi32.lib
  SET output=/Fe.\bin\codebase /Fo.\bin\int\
  SET defines=/D_DEBUG /D_CRT_SECURE_NO_WARNINGS
)

if %cc% == clang (
  SET compiler_flags=-Wall -Wvarargs -Werror -Wno-unused-function -Wno-format-security -Wno-incompatible-pointer-types-discards-qualifiers -Wno-unused-but-set-variable -Wno-int-to-void-pointer-cast
  SET include_flags=-Isource -Ithird_party/include -Ithird_party/source
  SET linker_flags=-g -lshell32 -luser32 -lwinmm -luserenv -lgdi32 -Lthird_party/lib
  SET output=-obin/codebase.exe
  SET defines=-D_DEBUG -D_CRT_SECURE_NO_WARNINGS -D%backend%
)

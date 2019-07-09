@echo off
echo 清除 Code Composer Studio 垃圾过程中，请稍等......
del \s\q *.prefs
del \s\q *.launch
del \s\q *.ccxml
del .ccsproject
for /f "delims=" %%i in ('dir /b/s/o-d/ad^|findstr /c:".launches"') do (
	rd /s/q "%%i"
)
for /f "delims=" %%i in ('dir /b/s/o-d/ad^|findstr /c:".settings"') do (
	rd /s/q "%%i"
)
for /f "delims=" %%i in ('dir /b/s/o-d/ad^|findstr /c:"targetConfigs"') do (
	rd /s/q "%%i"
)
for /f "delims=" %%i in ('dir /b/s/o-d/ad^|findstr /c:"Debug"') do (
	rd /s/q "%%i"
)
for /f "delims=" %%i in ('dir /b/s/o-d/ad^|findstr /c:"Release"') do (
	rd /s/q "%%i"
)
echo 清除 Code Composer Studio 垃圾完成！按任意键继续......
echo.
pause


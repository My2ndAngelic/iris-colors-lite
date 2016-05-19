@echo off

git add --all
git commit -m "Improving Iris colors lite %1"
git push

if not "%2" == "nopause" (
REM   pause
)
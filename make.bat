@echo off

start "" "D:\work\tools\TextPad\TextPad.exe" "ram.inc" "macroses.inc" "bank5.inc" "bank6.inc" "bank7.inc" "apu_player.inc" "scroller.inc" "script\script_us.inc" "script\font_us.inc" "script\script_jp.inc" "script\font_jp.inc"

pause 0

:again

call build.bat

pause 0

goto :again

:eof

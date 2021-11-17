@echo off

del !ramboprev.nes
rename !rambo.nes !ramboprev.nes

cd nas

echo assemble...

rem to draw dasm output
dasm bank0.nas -f3 -obank0.bin
rem to generate lst and err files
dasm bank1.nas -f3 -l!rambo.lst -obank1.bin >> !err.log

call :dodasm bank2.nas > NUL
call :dodasm bank3.nas > NUL
call :dodasm bank4.nas > NUL
call :dodasm bank5.nas > NUL
call :dodasm bank6.nas > NUL
call :dodasm bank7.nas > NUL
call :dodasm hdr.nas > NUL

goto :build

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

dasm hdr.nas -f3 -ohdr.bin > NUL

:build
echo build...

rename hdr.bin !rambo.hdr > NUL
copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin+bank4.bin+bank5.bin+bank6.bin+bank7.bin !rambo.prg > NUL
nesimage j !rambo > NUL

echo cleanup...
for %%f in (*.bin) do del %%f > NUL
del !rambo.hdr > NUL
del !rambo.prg > NUL

copy /b !rambo.nes ..\!rambo.nes > NUL

del !rambo.nes > NUL

cd ..

echo ===OLD ROM===
if exist !ramboprev.nes nas\m3checksum !ramboprev.nes
echo ===NEW ROM===
if exist !rambo.nes nas\m3checksum !rambo.nes

echo done.

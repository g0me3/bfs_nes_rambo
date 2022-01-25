cd nas

echo assemble...

for f in *.nas; do ./dasm $f -f3 -o"${f%.nas}.bin"; done

echo build...

mv hdr.bin !rambo.hdr

cat bank0.bin bank1.bin bank2.bin bank3.bin bank4.bin bank5.bin bank6.bin bank7.bin > !rambo.prg
cat !rambo.hdr !rambo.prg > !rambo.nes

echo cleanup...

rm *.bin
rm !rambo.hdr !rambo.prg

cp !rambo.nes ../!rambo.nes

rm !rambo.nes

cd ..

echo done.

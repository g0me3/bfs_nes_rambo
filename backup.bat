mkdir .\backup\current
mkdir .\backup\current\nas
mkdir .\backup\current\chr
mkdir .\backup\current\doc
mkdir .\backup\current\levels
mkdir .\backup\current\mus
mkdir .\backup\current\script

copy /b *.bat .\backup\current\*.bat
copy /b *.inc .\backup\current\*.inc
copy /b nas\*.exe .\backup\current\nas\*.exe
copy /b nas\*.nas .\backup\current\nas\*.nas
copy /b chr\*.inc .\backup\current\chr\*.inc
copy /b doc\*.txt .\backup\current\doc\*.txt
copy /b levels\*.inc .\backup\current\levels\*.inc
copy /b mus\*.inc .\backup\current\mus\*.inc
copy /b script\*.inc .\backup\current\script\*.inc
copy /b *.txt .\backup\current\*.txt

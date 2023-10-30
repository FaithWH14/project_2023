rmdir /q /s build

mkdir build
cd build

cmake ..

cmake --build . --config Release

cd Release

:: THIS IS TO OUTPUT THE PRINTED LOG INTO A FILE
simple_math.exe > ../../result_log.txt

cd ../..

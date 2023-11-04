rmdir /q /s build
mkdir build
cd build

cmake -S ..
cmake --build . --config Release

Release\\run_math.exe > ../../run_math_log.txt
cd ..
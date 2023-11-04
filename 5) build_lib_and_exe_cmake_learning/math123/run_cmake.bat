rmdir /q /s build
mkdir build
cd build

cmake -S ..
cmake --build . --config Release

cd ..
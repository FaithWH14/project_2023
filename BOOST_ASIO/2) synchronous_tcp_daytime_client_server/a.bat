rmdir /q /s build

mkdir build
cd build

cmake ..
cmake --build . --config Release

cd Release
asio_learn.exe

cd ../..

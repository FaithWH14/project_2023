rmdir /q /s build

mkdir build
cd build

cmake ..
cmake --build . --config Release

cd Release

learn_asio.exe

cd ../..
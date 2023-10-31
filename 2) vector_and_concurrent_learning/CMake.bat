rmdir /q /s build

mkdir build
cd build

cmake ..
cmake --build . --config Release

cd Release

vector_learn.exe >> ../../output_log.txt

cd ../..

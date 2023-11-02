rmdir /s /q build

mkdir build
cd build

cmake ..
cmake --build . --config Release

cd Release

set log_file=../../learn_log.txt
echo THIS IS THE OUTPUT OF LEARN.EXE LOG > %log_file%
learn.exe >> %log_file%

cd ../..

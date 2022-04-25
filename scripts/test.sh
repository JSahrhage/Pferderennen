cmake -S ./src -B ./build
cmake --build build
cd build && ctest
read -n 1 -s

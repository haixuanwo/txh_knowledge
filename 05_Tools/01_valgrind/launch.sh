
###
 # @Author: Clark
 # @Email: haixuanwoTxh@gmail.com
 # @Date: 2024-06-18 14:37:16
 # @LastEditors: Clark
 # @LastEditTime: 2024-06-18 14:39:02
 # @Description: file content
###

cd build
# rm -rf *
cmake ..
make -j8
# ../valgrind -s ./01_uninit_ptr
# ../valgrind -s ./02_use_free_memory
# ../valgrind -s --leak-check=full ./03_overrun_memory
# ../valgrind -s --leak-check=full ./04_memory_leak
../valgrind -s --leak-check=full ./05_mismacth

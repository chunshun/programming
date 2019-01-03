- 添加生成静态库
    `aux_source_directory(. DIRS)`
    `aux_source_directory(. DIR_SRCS)`
    `add_library(MathFunctions ${DIRS})`
    `add_executable(Demo ${DIR_SRCS})`
    `target_link_libraries(Demo MathFunctions)`
- 添加子目录
  - `add_subdirectory(math)`
- 安装和测试
  - `install`:`make install`
    - `install (TARGETS Demo DESTINATION bin)`:`Demo`以及生成的`libMathFunctions.so`安装到`usr/local/bin`
  - `test`:`make test`
- d打包
  - `cpack -C CPackConfig.cmake`: 生成二进制安装包
  - `cpack -C CPackSourceConfig.cmake`:生成源码安装包
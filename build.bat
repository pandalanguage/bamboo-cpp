@echo off
title Bamboo-Cpp 构建脚本
echo Bamboo-Cpp 构建脚本
echo 警告：本脚本仅供开发人员调试，如有问题请勿求助。
pause
echo 步骤一：生成构建系统
cd .cmake
cmake -G"MinGW Makefiles" ..
echo 步骤二：编译为可执行文件
cmake --build .
pause
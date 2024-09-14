#2. Укажите минимальную обязательную версию cmake для проекта 3.20
cmake_minimum_required(VERSION 3.20)
#3. Укажите компилятор для проекта
set(CMAKE_CXX_COMPILER "g++")
#4. Создайте проект и выберите язык C++ для него
project(CMakeProject_1_week_task-1 LANGUAGES CXX)
#5. Укажите стандарт C++17 для проекта как обязательный
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 6. Укажите исполняемые файлы в проект
add_executable (CMakeProject_1_week_task-1 "CMakeProject_1_week_task-1.cpp" "CMakeProject_1_week_task-1.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

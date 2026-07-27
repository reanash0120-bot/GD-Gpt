cmake_minimum_required(VERSION 3.21)
project(gd_gpt)

find_package(Geode REQUIRED)

add_geode_mod(gd_gpt)

target_sources(gd_gpt PRIVATE
    src/main.cpp
)

#!/bin/bash

BUILD_DIR=$1

mkdir -p coverage/html
mkdir -p coverage/gcov
mkdir -p coverage/lcov

cd coverage/gcov
gcov ../../test/001_buffer_full/*.cpp --object-directory ../../$BUILD_DIR/test/001_buffer_full/CMakeFiles/001_buffer_full.dir/
gcov ../../test/002_tail_wrap/*.cpp --object-directory ../../$BUILD_DIR/test/002_tail_wrap/CMakeFiles/002_tail_wrap.dir/
gcov ../../test/003_head_wrap/*.cpp --object-directory ../../$BUILD_DIR/test/003_head_wrap/CMakeFiles/003_head_wrap.dir/
gcov ../../test/004_api_at/*.cpp --object-directory ../../$BUILD_DIR/test/004_api_at/CMakeFiles/004_api_at.dir/
gcov ../../test/005_api_brackets/*.cpp --object-directory ../../$BUILD_DIR/test/005_api_brackets/CMakeFiles/005_api_brackets.dir/
gcov ../../test/006_api_copy_constructor/*.cpp --object-directory ../../$BUILD_DIR/test/006_api_copy_constructor/CMakeFiles/006_api_copy_constructor.dir/
gcov ../../test/007_api_move_constructor/*.cpp --object-directory ../../$BUILD_DIR/test/007_api_move_constructor/CMakeFiles/007_api_move_constructor.dir/
gcov ../../test/008_api_copy_assignment/*.cpp --object-directory ../../$BUILD_DIR/test/008_api_copy_assignment/CMakeFiles/008_api_copy_assignment.dir/
gcov ../../test/009_api_move_assignment/*.cpp --object-directory ../../$BUILD_DIR/test/009_api_move_assignment/CMakeFiles/009_api_move_assignment.dir/
gcov ../../test/010_api_front/*.cpp --object-directory ../../$BUILD_DIR/test/010_api_front/CMakeFiles/010_api_front.dir/
gcov ../../test/011_api_back/*.cpp --object-directory ../../$BUILD_DIR/test/011_api_back/CMakeFiles/011_api_back.dir/
gcov ../../test/012_api_empty/*.cpp --object-directory ../../$BUILD_DIR/test/012_api_empty/CMakeFiles/012_api_empty.dir/
gcov ../../test/013_api_size/*.cpp --object-directory ../../$BUILD_DIR/test/013_api_size/CMakeFiles/013_api_size.dir/
gcov ../../test/014_api_clear/*.cpp --object-directory ../../$BUILD_DIR/test/014_api_clear/CMakeFiles/014_api_clear.dir/
gcov ../../test/015_api_push_rvalue/*.cpp --object-directory ../../$BUILD_DIR/test/015_api_push_rvalue/CMakeFiles/015_api_push_rvalue.dir/
gcov ../../test/016_api_full/*.cpp --object-directory ../../$BUILD_DIR/test/016_api_full/CMakeFiles/016_api_full.dir/
gcov ../../test/017_api_emplace_back/*.cpp --object-directory ../../$BUILD_DIR/test/017_api_emplace_back/CMakeFiles/017_api_emplace_back.dir/
gcov ../../test/018_pop_front/*.cpp --object-directory ../../$BUILD_DIR/test/018_pop_front/CMakeFiles/018_pop_front.dir/
gcov ../../test/019_api_swap/*.cpp --object-directory ../../$BUILD_DIR/test/019_api_swap/CMakeFiles/019_api_swap.dir/
gcov ../../test/020_api_iterator/*.cpp --object-directory ../../$BUILD_DIR/test/020_api_iterator/CMakeFiles/020_api_iterator.dir/
gcov ../../test/021_api_const_iterator/*.cpp --object-directory ../../$BUILD_DIR/test/021_api_const_iterator/CMakeFiles/021_api_const_iterator.dir/
gcov ../../test/022_api_reverse_iterator/*.cpp --object-directory ../../$BUILD_DIR/test/022_api_reverse_iterator/CMakeFiles/022_api_reverse_iterator.dir/
gcov ../../test/023_api_const_reverse_iterator/*.cpp --object-directory ../../$BUILD_DIR/test/023_api_const_reverse_iterator/CMakeFiles/023_api_const_reverse_iterator.dir/
cd -

cd coverage/lcov
lcov --directory ../../$BUILD_DIR/test/001_buffer_full/CMakeFiles/001_buffer_full.dir/ -c -o 001_buffer_full.info
lcov --directory ../../$BUILD_DIR/test/002_tail_wrap/CMakeFiles/002_tail_wrap.dir/ -c -o 002_tail_wrap.info
lcov --directory ../../$BUILD_DIR/test/003_head_wrap/CMakeFiles/003_head_wrap.dir/ -c -o 003_head_wrap.info
lcov --directory ../../$BUILD_DIR/test/004_api_at/CMakeFiles/004_api_at.dir/ -c -o 004_api_at.info
lcov --directory ../../$BUILD_DIR/test/005_api_brackets/CMakeFiles/005_api_brackets.dir/ -c -o 005_api_brackets.info
lcov --directory ../../$BUILD_DIR/test/006_api_copy_constructor/CMakeFiles/006_api_copy_constructor.dir/ -c -o 006_api_copy_constructor.info
lcov --directory ../../$BUILD_DIR/test/007_api_move_constructor/CMakeFiles/007_api_move_constructor.dir/ -c -o 007_api_move_constructor.info
lcov --directory ../../$BUILD_DIR/test/008_api_copy_assignment/CMakeFiles/008_api_copy_assignment.dir/ -c -o 008_api_copy_assignment.info
lcov --directory ../../$BUILD_DIR/test/009_api_move_assignment/CMakeFiles/009_api_move_assignment.dir/ -c -o 009_api_move_assignment.info
lcov --directory ../../$BUILD_DIR/test/010_api_front/CMakeFiles/010_api_front.dir/ -c -o 010_api_front.info
lcov --directory ../../$BUILD_DIR/test/011_api_back/CMakeFiles/011_api_back.dir/ -c -o 011_api_back.info
lcov --directory ../../$BUILD_DIR/test/012_api_empty/CMakeFiles/012_api_empty.dir/ -c -o 012_api_empty.info
lcov --directory ../../$BUILD_DIR/test/013_api_size/CMakeFiles/013_api_size.dir/ -c -o 013_api_size.info
lcov --directory ../../$BUILD_DIR/test/014_api_clear/CMakeFiles/014_api_clear.dir/ -c -o 014_api_clear.info
lcov --directory ../../$BUILD_DIR/test/015_api_push_rvalue/CMakeFiles/015_api_push_rvalue.dir/ -c -o 015_api_push_rvalue.info
lcov --directory ../../$BUILD_DIR/test/016_api_full/CMakeFiles/016_api_full.dir/ -c -o 016_api_full.info
lcov --directory ../../$BUILD_DIR/test/017_api_emplace_back/CMakeFiles/017_api_emplace_back.dir/ -c -o 017_api_emplace_back.info
lcov --directory ../../$BUILD_DIR/test/018_pop_front/CMakeFiles/018_pop_front.dir/ -c -o 018_pop_front.info
lcov --directory ../../$BUILD_DIR/test/019_api_swap/CMakeFiles/019_api_swap.dir/ -c -o 019_api_swap.info
lcov --directory ../../$BUILD_DIR/test/020_api_iterator/CMakeFiles/020_api_iterator.dir/ -c -o 020_api_iterator.info
lcov --directory ../../$BUILD_DIR/test/021_api_const_iterator/CMakeFiles/021_api_const_iterator.dir/ -c -o 021_api_const_iterator.info
lcov --directory ../../$BUILD_DIR/test/022_api_reverse_iterator/CMakeFiles/022_api_reverse_iterator.dir/ -c -o 022_api_reverse_iterator.info
lcov --directory ../../$BUILD_DIR/test/023_api_const_reverse_iterator/CMakeFiles/023_api_const_reverse_iterator.dir/ -c -o 023_api_const_reverse_iterator.info

lcov \
-a 001_buffer_full.info \
-a 002_tail_wrap.info \
-a 003_head_wrap.info \
-a 004_api_at.info \
-a 005_api_brackets.info \
-a 006_api_copy_constructor.info \
-a 007_api_move_constructor.info \
-a 008_api_copy_assignment.info \
-a 009_api_move_assignment.info \
-a 010_api_front.info \
-a 011_api_back.info \
-a 012_api_empty.info \
-a 013_api_size.info \
-a 014_api_clear.info \
-a 015_api_push_rvalue.info \
-a 016_api_full.info \
-a 017_api_emplace_back.info \
-a 018_pop_front.info \
-a 019_api_swap.info \
-a 020_api_iterator.info \
-a 021_api_const_iterator.info \
-a 022_api_reverse_iterator.info \
-a 023_api_const_reverse_iterator.info \
-o coverage_report.info
cd -

genhtml coverage/lcov/coverage_report.info -o coverage/html

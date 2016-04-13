root_include_dir :=thirdparty
root_source_dir :=test
source_subdirs    := . dir1 dir2
compile_flags      := -Wall -MD -pipe
link_flags            := -s -pipe
libraries               := -ldl
all : Crypt
Crypt : obj_dirs $(objects)
	g++ -o $@ $(objects) $(link_flags) $(libraries)
obj_dirs :
%.o : %.cpp
	g++ -o $@ -c $< $(compile_flags) $(build_flags) $(addprefix -I, $(relative_include_dirs))
%.o : %.c
	g++ -o $@ -c $< $(compile_flags) $(build_flags) $(addprefix -I, $(relative_include_dirs))
.PHONY : clean
clean :
	rm -rf bin obj

include $(wildcard $(addsuffix /*.d, $(objects_dirs)))

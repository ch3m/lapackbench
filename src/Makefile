MKDIR_P = mkdir -p
TARGET = lapack_bench

# all: variables directories program
all: variables program

variables:
ifeq ($(ARCH),gnu)
CXX := g++
SPEC_FLAGS := -O3
else ifeq ($(ARCH),gnu_openmp)
CXX := g++
SPEC_FLAGS := -O3 -fopenmp
else
ARCH := "none"
CXX := g++
SPEC_FLAGS := 
endif
#GEN_FLAGS := -vec-report3 
		
# directories: bin

# bin:
# 	${MKDIR_P} bin

program:
	@echo "arquitectura: $(ARCH)"
	@echo "Compilador: ${CXX}"
	${CXX} ${SPEC_FLAGS} ${GEN_FLAGS} ${TARGET}.cc -o ${TARGET}

clean:
	rm -rf ${TARGET}

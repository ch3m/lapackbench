MKDIR_P = mkdir -p
TARGET = lapack_bench

# all: variables directories program
all: variables program

variables:
ifeq ($(ARCH),gnu)
CXX := g++
SPEC_FLAGS := -O3  -ftree-vectorizer-verbose=2
else ifeq ($(ARCH),gnu_openmp)
CXX := g++
SPEC_FLAGS := -O3 -fopenmp -ftree-vectorizer-verbose=7 -Wall
else ifeq ($(ARCH),intel)
CXX := icpc
SPEC_FLAGS := -O3 -fopenmp -vec-report=1 -restrict
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

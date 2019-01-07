# Time-stamp: <2019-01-06 09:50:13 macbookair>

# CC = g++  
CC = /usr/local/Cellar/gcc/8.2.0/bin/g++-8

SRC_DIR := src/
OBJ_DIR := build/
INCLUDE_DIR := include/
NEWINSILICO_DIR := /Users/macbookair/goofy/software/new_insilico

LIB_DIR := lib/
LIB_NAME := libnew_insilico.a

ODE_STOCH_PATH := /Users/macbookair/goofy/software/kurunari/include
BOOST_ROOT_PATH := /usr/local/include/boost
BOOST_LIBS_PATH := /usr/local/opt/boost/lib
BOOST_ODEINT_PATH := /usr/local/Cellar/boost/1.68.0/include

SRC := $(wildcard $(SRC_DIR)*.cpp)
OBJ := $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC)) 
OBJ := $(patsubst %.cpp, %.o, $(OBJ))
DEPS := $(wildcard $(INCLUDE_DIR)*.hpp)

# CCFLAGS := -std=c++11 -stdlib=libc++ -Wall -I$(NEWINSILICO_DIR)
CCFLAGS := -std=c++11 -Wall -I$(NEWINSILICO_DIR) -I$(BOOST_ROOT_PATH) -I$(BOOST_LIBS_PATH) -I$(BOOST_ODEINT_PATH)
# CCFLAGS := -Wall -I$(NEWINSILICO_DIR)

all: $(LIB_DIR)$(LIB_NAME)

# pattern rule for c++ files in the src directory
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp
	@echo "Compiling..."$<
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJ_DIR)*
	@rm -f $(LIB_DIR)*
print:
	@echo SRC=$(SRC)
	@echo DEPS=$(DEPS)
	@echo OBJ=$(OBJ)
	@echo $(LIB_DIR)$(LIB_NAME)

$(LIB_DIR)$(LIB_NAME): $(OBJ)
	@echo "building library "$@ 
	@ar -vsr $@ $^

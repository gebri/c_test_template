LINK_TARGET = hello
OBJS = utils.o 

TEST_TARGET = test_runner
TEST_OBJS = test.o

REBUILDABLES = $(OBJS) ${TEST_OBJS} $(LINK_TARGET) ${TEST_TARGET}

%.o : %.c
	cc -g -o $@ -c $<

$(LINK_TARGET) : $(OBJS) hello.o
	cc -g -o $@ $^

$(TEST_TARGET) : $(OBJS) $(TEST_OBJS)
	cc -g -o $@ $^

all: $(LINK_TARGET)

test: ${TEST_TARGET}
	./${TEST_TARGET}

clean:
	rm -f ${REBUILDABLES}

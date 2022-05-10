CXX = g++
CXXFLAGS = -std=c++14 -Isrc/classes -Isrc/exceptions -Isrc/commands -g -Wall -MMD
EXEC = emulator
OBJECTS = src/main.o src/commands/Print.o src/commands/Mem.o src/commands/Beq.o src/commands/Bne.o src/commands/Jr.o src/commands/Lw.o src/commands/Sw.o src/commands/Slt.o src/classes/LabelTable.o src/classes/MipsClient.o src/classes/MipsDFA.o src/classes/Token.o src/commands/Sub.o src/commands/Mflo.o src/commands/Add.o src/commands/AddI.o src/commands/Div.o src/commands/Mfhi.o src/commands/Mult.o src/commands/CommandFactory.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

shield: .shield.c++ .shieldagent.c++ .shieldagent1.c++ .shieldcase.c++ passwd.c++
	c++ -g  .shield.c++ .shieldagent.c++ .shieldagent1.c++ .shieldcase.c++ passwd.c++ -o shield
	@echo "\nCompilation succesfull"
clean:
	rm .shield.c++ .shieldagent.c++ .shieldagent1.c++ .shieldcase.c++ shield.h shield.txt passwd.c++ passwd.h

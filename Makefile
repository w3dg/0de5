help:
	@echo clean: cleans up all executables from the dir
	@echo
	@echo Makefiles for individual chapters are present in respective dirs

clean:
	find . -type f -executable -exec rm {} \;
